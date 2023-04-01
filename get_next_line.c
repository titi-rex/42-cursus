/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/01 11:48:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	s_buff[BUFFER_SIZE + 1];
	char		*line;
	size_t		idx;
	size_t		size;
	int			n_read;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	line = gnl_init(&idx, &size, &n_read);
	while (!gnl_chr_nl(line))
	{
		if (s_buff[0] == 0)
			n_read = read(fd, s_buff, BUFFER_SIZE);
		if (n_read == -1)
			return (free(line), NULL);
		else if (n_read == 0)
			return (line);
		if (idx == size - 1)
			line = gnl_expand(line, &size);
		if (!line)
			return (NULL);
		idx = gnl_strlcat(line, s_buff, idx);
		gnl_refresh(s_buff);
	}
	return (line);
}
