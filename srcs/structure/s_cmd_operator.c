/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmd_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:50:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 23:03:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*ft_cmd_last(t_cmd *cmd)
{
	if (cmd)
	{
		while (cmd->next)
			cmd = cmd->next;
	}
	return (cmd);
}

t_cmd	*ft_cmd_first(t_cmd *cmd)
{
	if (cmd)
	{
		while (cmd->previous)
			cmd = cmd->previous;
	}
	return (cmd);
}

void	ft_cmd_clear_lst(t_cmd	**cmd)
{
	t_cmd	*tmp;
	t_cmd	*idx;

	idx = (*cmd)->next;
	while (*cmd)
	{
		tmp = (*cmd)->previous;
		ft_cmd_del(*cmd);
		*cmd = tmp;
	}
	*cmd = idx;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		ft_cmd_del(*cmd);
		*cmd = tmp;
	}
}

void	ft_cmd_add_back(t_cmd **start, t_cmd *new)
{
	t_cmd	*tmp;

	if (!start || !new)
		return ;
	if (!*start)
		*start = new;
	else
	{
		tmp = ft_cmd_last(*start);
		tmp->next = new;
		new->previous = tmp;
	}
}
