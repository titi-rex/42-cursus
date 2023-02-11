/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:56:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/11 20:51:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free2d(void **arr, int size)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (!size)
	{
		while (arr[++i])
		{
			if (arr[i])
				free(arr[i]);
		}
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

void	ft_close(t_pipex *cmd_line)
{
	if (cmd_line->fds[0] != -1)
		close(cmd_line->fds[0]);
	cmd_line->fds[0] = -1;
	if (cmd_line->fds[1] != -1)
		close(cmd_line->fds[1]);
	cmd_line->fds[1] = -1;
	if (cmd_line->pipefd[0][0] != -1)
	{
		close(cmd_line->pipefd[0][0]);
		close(cmd_line->pipefd[0][1]);
		cmd_line->pipefd[0][0] = -1;
		cmd_line->pipefd[0][1] = -1;
	}
	if (cmd_line->pipefd[1][0] != -1)
	{
		close(cmd_line->pipefd[1][0]);
		close(cmd_line->pipefd[1][1]);
		cmd_line->pipefd[1][0] = -1;
		cmd_line->pipefd[1][1] = -1;
	}
}

void	ft_clean_exit(t_pipex *cmd_line, int exit_code)
{
	if (cmd_line->cmds)
		ft_free3d((void ***) cmd_line->cmds, 0, NULL);
	if (cmd_line->cmdio)
		ft_free2d((void **) cmd_line->cmdio, cmd_line->n_cmd);
	ft_close(cmd_line);
	exit(exit_code);
}
