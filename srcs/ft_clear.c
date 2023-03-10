/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 14:05:40 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_clear_lst_io(t_redirect *io)
{
	if (!io)
		return ;
	if (io->arg)
		free(io->arg);
	ft_clear_lst_io(io->next);
}

void	ft_clear_cmd(t_cmd **cmd)
{
	if ((*cmd)->arg)
		ft_free2d((void **)(*cmd)->arg, 0);
	ft_clear_lst_io((*cmd)->io);
	*cmd = NULL;
	cmd = NULL;
}

void	ft_clear_lst_cmd_previous(t_cmd **cmd)
{
	t_cmd	*previous;

	if (!cmd || !*cmd)
		return ;
	previous = (*cmd)->previous;
	ft_clear_cmd(cmd);
	ft_clear_lst_cmd_previous(&previous);
}

void	ft_clear_lst_cmd_next(t_cmd **cmd)
{
	t_cmd	*next;

	if (!cmd || !*cmd)
		return ;
	next = (*cmd)->next;
	ft_clear_cmd(cmd);
	ft_clear_lst_cmd_next(&next);
}

void	ft_clear_line(t_line *line)
{
	if (line->cmd)
	{
		ft_clear_lst_cmd_previous(&line->cmd->previous);
		ft_clear_lst_cmd_next(&line->cmd);
	}
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
