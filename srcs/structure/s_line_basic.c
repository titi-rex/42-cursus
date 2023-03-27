/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_line_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 11:14:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	s_line_init(t_line *line)
{
	line->cmd = NULL;
	line->env = NULL;
	line->lst_env = NULL;
	line->pipe[0][0] = -1;
	line->pipe[0][1] = -1;
	line->pipe[1][0] = -1;
	line->pipe[1][1] = -1;
	line->fd_std[0] = dup(STDIN_FILENO);
	line->fd_std[1] = dup(STDOUT_FILENO);
	if (line->fd_std[0] == -1 || line->fd_std[1] == -1)
		perror("Error ");
	line->n_cmds = 0;
	line->exit_status = 0;
}

void	s_line_reset(t_line *line)
{
	if (line->cmd)
		s_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
}

void	s_line_clear(t_line *line)
{
	if (line->cmd)
		s_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	if (line->fd_std[0] != -1)
		close(line->fd_std[0]);
	if (line->fd_std[1] != -1)
		close(line->fd_std[1]);
	line->n_cmds = 0;
	ft_env_clear(&line->lst_env);
	ft_free2d((void **)line->env, 0);
}
