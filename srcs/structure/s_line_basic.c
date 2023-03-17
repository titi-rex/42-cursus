/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_line_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/17 17:12:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	s_line_init(t_line *line)
{
	line->cmd = NULL;
	line->pipe[0][0] = -1;
	line->pipe[0][1] = -1;
	line->pipe[1][0] = -1;
	line->pipe[1][1] = -1;
	line->fd_std[0] = dup(STDIN_FILENO);
	line->fd_std[1] = dup(STDOUT_FILENO);
	line->fd_std[2] = dup(STDERR_FILENO);
	if (line->fd_std[0] == -1 || line->fd_std[1] == -1 || line->fd_std[2] == -1)
		perror("Error ");
	line->n_cmds = 0;
	line->exit_status = 0;
	line->env = NULL;
}

void	s_line_reset(t_line *line)
{
	if (line->cmd)
		ft_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
}

void	s_line_clear(t_line *line)
{
	if (line->cmd)
		ft_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
	ft_envclear(&line->lst_env);
	//ft_free2d((void **)line->env, 0);
}
