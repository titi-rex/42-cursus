/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 14:36:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_reset_line(t_line *line)
{
	if (line->cmd)
		ft_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
}

void	ft_clear_line(t_line *line)
{
	if (line->cmd)
		ft_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
	//ft_envclear(&line->lst_env);
	//ft_free2d((void **)line->env, 0);
}

void	ft_clear_line_exit(t_line *line, int exit_code)
{
	ft_clear_line(line);
	exit(exit_code);
}
