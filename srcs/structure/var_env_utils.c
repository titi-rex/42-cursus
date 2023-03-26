/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:33:56 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/26 12:09:53 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*ft_env_new(char *name, char *value)
{
	t_var_env	*new;

	new = (t_var_env *)malloc(sizeof(t_var_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->previous = NULL;
	new->name = ft_strndup(name, ft_strlen2(name));
	if (!new->name)
		return (ft_env_free(new), NULL);
	if (!value)
		new->value = NULL;
	else
	{
		new->value = ft_strndup(value, ft_strlen2(value));
		if (!new->value)
			return (ft_env_free(new), NULL);
	}
	return (new);
}

void	ft_env_add_front(t_var_env **lst, t_var_env *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->previous = new;
	}
	*lst = new;
}

void	ft_env_add_back(t_var_env **lst, t_var_env *new)
{
	t_var_env	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_env_last(*lst);
		last->next = new;
		new->previous = last;
	}
}

void	ft_env_free(t_var_env *lst)
{
	if (!lst)
		return ;
	if (lst->name)
		free(lst->name);
	if (lst->value)
		free(lst->value);
	free(lst);
}

void	ft_env_remove(t_var_env **head, t_var_env *todel)
{
	t_var_env	*after;
	t_var_env	*before;

	if (!todel)
		return ;
	after = todel->next;
	before = todel->previous;
	ft_env_free(todel);
	if (before)
		before->next = after;
	else
		*head = after;
	if (after)
		after->previous = before;
}
