/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/06 23:23:36 by tlegrand         ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE < 1)
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
		if ((size_t)n_read >= size - idx)
			line = gnl_expand(line, &size);
		if (!line)
			return (NULL);
		idx = gnl_strlcat(line, s_buff, idx);
		gnl_refresh(s_buff);
	}
	return (line);
}
