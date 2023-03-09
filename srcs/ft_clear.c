/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 14:17:17 by tlegrand         ###   ########.fr       */
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

void	ft_clear_cmd(t_cmd *cmd)
{
	if (cmd->cmd)
		ft_free2d((void **)cmd->cmd, 0);
	ft_clear_lst_io(cmd->io);
}

void	ft_clear_lst_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_clear_cmd(cmd);
	ft_clear_lst_cmd(cmd->previous);
	ft_clear_lst_cmd(cmd->next);
}

void	ft_clear_line(t_line *line)
{
	ft_clear_lst_cmd(line->cmd);
	ft_close_pipe(line->pipe[0]);
	ft_close_pipe(line->pipe[1]);
	//ft_clear_env(line->env);
}

void	ft_clear_line_exit(t_line *line, int exit_code)
{
	ft_clear_line(line);
	exit(exit_code);
}
