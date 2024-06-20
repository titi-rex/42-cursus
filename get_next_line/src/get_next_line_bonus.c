/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:27:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/10 15:56:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	s_buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	size_t		idx;
	size_t		size;
	int			n_read;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	line = gnl_init(&idx, &size, &n_read);
	while (!gnl_chr_nl(line))
	{
		if (s_buff[fd][0] == 0)
			n_read = read(fd, s_buff[fd], BUFFER_SIZE);
		if (n_read == -1)
			return (free(line), NULL);
		else if (n_read == 0)
			return (line);
		if ((size_t)n_read >= size - idx)
			line = gnl_expand(line, &size);
		if (!line)
			return (NULL);
		idx = gnl_strlcat(line, s_buff[fd], idx);
		gnl_refresh(s_buff[fd]);
	}
	return (line);
}
