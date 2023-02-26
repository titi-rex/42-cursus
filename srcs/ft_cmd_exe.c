/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:30:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/26 19:35:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_cmd_exe(t_pipex *cmd_l, int i, int fd_in, int fd_out)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Fork failed ", NULL, &cmd_l->err);
	else if (pid == 0)
	{
		if (fd_in != -1 && fd_out != -1)
		{
			if (dup2(fd_in, 0) == -1 || dup2(fd_out, 1) == -1)
				ft_error("Dup failed ", NULL, &cmd_l->err);
			ft_close(cmd_l);
			if (!cmd_l->cmds[i][0])
				ft_clean_exit(cmd_l, EXIT_FAILURE);
			if (execve(cmd_l->cmds[i][0], cmd_l->cmds[i], cmd_l->env) == -1)
				ft_error("Execution failed ", cmd_l->cmds[i][0], &cmd_l->err);
		}
		ft_clean_exit(cmd_l, EXIT_FAILURE);
	}
}

void	ft_cmd_master(t_pipex *cmd_l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (i < cmd_l->n_cmd)
	{
		j = i % 2;
		if (pipe(cmd_l->pipe[j]) == -1)
			ft_error("Pipe failed", NULL, &cmd_l->err);
		if (i == 0)
			ft_cmd_exe(cmd_l, i, cmd_l->fds[0], cmd_l->pipe[0][1]);
		else if (i == cmd_l->n_cmd - 1)
			ft_cmd_exe(cmd_l, i, cmd_l->pipe[j + k][0], cmd_l->fds[1]);
		else
			ft_cmd_exe(cmd_l, i, cmd_l->pipe[j + k][0], cmd_l->pipe[j][1]);
		ft_close_pipe(cmd_l->pipe[j + k]);
		i++;
		k *= -1;
	}
	ft_close_pipe(cmd_l->pipe[j]);
	while (i-- > 0)
		wait(NULL);
}
