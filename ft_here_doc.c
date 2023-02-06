/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:35:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/06 17:16:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *end)
{
	int		fd;
	int		n_read;
	int		len_end;
	char	buff[100];

	fd = open(HERE_DOC, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	n_read = 1;
	len_end = ft_strlen(end);
	while (n_read)
	{
		n_read = read(0, &buff, 100);
		if (n_read == -1)
			break ;
		buff[n_read] = 0;
		if (!ft_strncmp(buff, end, len_end) && buff[len_end] == '\n')
			break ;
		write(fd, &buff, n_read);
	}
	close(fd);
	return (0);
}
