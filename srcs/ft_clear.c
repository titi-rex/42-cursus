/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 23:01:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_clear_line(t_line *line)
{
	if (line->cmd)
		ft_cmd_clear_lst(&line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	line->n_cmds = 0;
	line->exit_status = EXIT_SUCCESS;
}

void	ft_clear_line_exit(t_line *line, int exit_code)
{
	ft_clear_line(line);
	//ft_envclear(line->env);
	exit(exit_code);
}

/*	old clear io
void	ft_clear_lst_io(t_redirect *io)
{
	if (!io)
		return ;
	if (io->arg)
		free(io->arg);
	ft_clear_lst_io(io->next);
}
*/