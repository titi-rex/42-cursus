/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:18:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 22:32:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	s_init_varfd(t_varfd *varfd)
{
	varfd->varname = NULL;
	varfd->fd = 10;
	varfd->next = NULL;
}

void	s_init_redirect(t_redirect *io)
{
	io->type = 0;
	io->fd = 0;
	io->arg = NULL;
	io->next = NULL;
}

void	s_init_cmd(t_cmd *cmd)
{
	cmd->arg = NULL;
	cmd->io = NULL;
	cmd->next = NULL;
	cmd->previous = NULL;
}

void	s_init_line(t_line *line)
{
	line->cmd = NULL;
	line->pipe[0][0] = -1;
	line->pipe[0][1] = -1;
	line->pipe[1][0] = -1;
	line->pipe[1][1] = -1;
	line->n_cmds = 0;
	line->exit_status = 0;
	line->env = NULL;
}
