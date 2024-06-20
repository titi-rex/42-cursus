/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_var_env_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:33:56 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 16:06:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*s_env_new(char *name, char *value)
{
	t_var_env	*new;

	if (!name)
		return (NULL);
	new = (t_var_env *)malloc(sizeof(t_var_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->previous = NULL;
	new->name = ft_strndup(name, ft_strlen2(name));
	if (!new->name)
		return (s_env_del(new), NULL);
	if (!value)
		new->value = NULL;
	else
	{
		new->value = ft_strndup(value, ft_strlen2(value));
		if (!new->value)
			return (s_env_del(new), NULL);
	}
	return (new);
}

void	s_env_del(t_var_env *lst)
{
	if (!lst)
		return ;
	if (lst->name)
		free(lst->name);
	if (lst->value)
		free(lst->value);
	free(lst);
}

void	s_env_remove(t_var_env **head, t_var_env *todel)
{
	t_var_env	*after;
	t_var_env	*before;

	if (!todel)
		return ;
	after = todel->next;
	before = todel->previous;
	s_env_del(todel);
	if (before)
		before->next = after;
	else
		*head = after;
	if (after)
		after->previous = before;
}
