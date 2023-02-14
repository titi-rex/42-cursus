/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/14 19:42:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_get_fd(t_pipex *cmd_l, char **arg, int argc)
{
	int	n;

	n = argc - 1;
	if (access(arg[1], F_OK))
		ft_error("Can't open file (no such file) : ", arg[1]);
	else if (access(arg[1], R_OK))
		ft_error("Can't open file : (permission denied) : ", arg[1]);
	cmd_l->fds[0] = open(arg[1], O_RDONLY | O_CLOEXEC);
	cmd_l->fds[1] = open(arg[n], O_WRONLY | O_TRUNC | O_CLOEXEC | O_CREAT, 420);
	if (cmd_l->fds[1] == -1)
		ft_error("Can't open file : (permission denied) : ", arg[n]);
}
