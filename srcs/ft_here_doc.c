/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:35:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/13 21:42:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_here_doc(char *end, t_pipex *cmd_line)
{
	int		n_read;
	int		len_end;
	char	buff[100];

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
		write(cmd_line->pipe[1][1], &buff, n_read);
	}
	return (0);
}
