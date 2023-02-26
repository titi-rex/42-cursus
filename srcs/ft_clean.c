/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:56:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/26 19:29:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free2d(void **arr, int size)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (!size)
	{
		while (arr[++i])
			free(arr[i]);
	}
	else
	{
		while (++i < size)
		{
			if (arr[i])
				free(arr[i]);
		}
	}
	free(arr);
}

void	ft_free3d(void ***arr, int size3d, int *size2d)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (!size3d)
	{
		while (arr[++i])
			ft_free2d(arr[i], 0);
	}
	else
	{
		while (++i < size3d)
			ft_free2d(arr[i], size2d[i]);
	}
	free(arr);
}

void	ft_close_pipe(int pipefd[2])
{
	if (pipefd[0] != -1)
		close(pipefd[0]);
	pipefd[0] = -1;
	if (pipefd[1] != -1)
		close(pipefd[1]);
	pipefd[1] = -1;
}

void	ft_close(t_pipex *cmd_line)
{
	if (cmd_line->fds[0] != -1)
		close(cmd_line->fds[0]);
	cmd_line->fds[0] = -1;
	if (cmd_line->fds[1] != -1)
		close(cmd_line->fds[1]);
	cmd_line->fds[1] = -1;
	ft_close_pipe(cmd_line->pipe[0]);
	ft_close_pipe(cmd_line->pipe[1]);
}

void	ft_clean_exit(t_pipex *cmd_line, int exit_code)
{
	if (cmd_line->cmds)
		ft_free3d((void ***) cmd_line->cmds, 0, NULL);
	ft_close(cmd_line);
	exit(exit_code);
}
