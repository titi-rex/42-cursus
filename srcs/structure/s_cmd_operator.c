/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmd_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:50:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 11:14:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*s_cmd_last(t_cmd *cmd)
{
	if (cmd)
	{
		while (cmd->next)
			cmd = cmd->next;
	}
	return (cmd);
}

t_cmd	*s_cmd_first(t_cmd *cmd)
{
	if (cmd)
	{
		while (cmd->previous)
			cmd = cmd->previous;
	}
	return (cmd);
}

void	s_cmd_clear_lst(t_cmd	**cmd)
{
	t_cmd	*tmp;
	t_cmd	*idx;

	idx = (*cmd)->next;
	while (*cmd)
	{
		tmp = (*cmd)->previous;
		s_cmd_del(*cmd);
		*cmd = tmp;
	}
	*cmd = idx;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		s_cmd_del(*cmd);
		*cmd = tmp;
	}
}

void	s_cmd_add_back(t_cmd **start, t_cmd *new)
{
	t_cmd	*tmp;

	if (!start || !new)
		return ;
	if (!*start)
		*start = new;
	else
	{
		tmp = s_cmd_last(*start);
		tmp->next = new;
		new->previous = tmp;
	}
}

void	s_cmd_init(t_cmd *cmd)
{
	cmd->arg = NULL;
	cmd->io = NULL;
	cmd->next = NULL;
	cmd->previous = NULL;
}
