/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:30:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/13 18:00:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


void	ft_cmd_exe(t_pipex *cmd_l, int i, int k, int fd_in, int fd_out)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Fork failed ", NULL);
	else if (pid == 0)
	{
		if (fd_in != -1 && fd_out != -1)
		{
			dup2(fd_in, 0);
			dup2(fd_out, 1);
			ft_close(cmd_l);
			if (!cmd_l->cmds[i][0])
				ft_clean_exit(cmd_l, EXIT_FAILURE);
			if (execve(cmd_l->cmds[i][0], cmd_l->cmds[i], cmd_l->env) == -1)
				ft_error("Execve failed ", cmd_l->cmds[i][0]);
		}
		ft_clean_exit(cmd_l, EXIT_FAILURE);
	}
	else
		ft_close_pipe(cmd_l->pipe[i % 2 + k]);
}

void	ft_cmd_master(t_pipex *cmd_l)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i < cmd_l->n_cmd)
	{
		pipe(cmd_l->pipe[i % 2]);
		if (i == 0)
			ft_cmd_exe(cmd_l, i, k, cmd_l->fds[0], cmd_l->pipe[1][1]);
		else if (i == cmd_l->n_cmd - 1)
			ft_cmd_exe(cmd_l, i, k, cmd_l->pipe[i % 2][0], cmd_l->fds[1]);
		else
			ft_cmd_exe(cmd_l, i, k, cmd_l->pipe[i % 2][0], cmd_l->pipe[i % 2 + k][1]);
		i++;
		k *= -1;
	}
}
