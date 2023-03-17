/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmd_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:16:33 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/17 14:40:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*ft_cmd_new(char **arg, t_list *io)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->arg = arg;
	new->io = io;
	return (new);
}

t_cmd	*ft_cmd_new_alloc(char **arg, t_list *io)
{
	t_cmd	*new;
	int		i;

	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->arg = ft_calloc(ft_splitlen(arg) + 1, sizeof(void *));
	if (!new->arg)
		return (free(new), NULL);
	i = 0;
	while (arg[i])
	{
		new->arg[i] = ft_strdup(arg[i]);
		if (!new->arg[i])
		{
			ft_free2d((void **) new->arg, 0);
			free(new);
		}
		i++;
	}
	new->io = io;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_cmd_del(t_cmd *cmd)
{
	if (cmd->arg)
		ft_free2d((void **)cmd->arg, 0);
	ft_lstclear(&cmd->io, ft_redirect_del);
	free(cmd);
}
