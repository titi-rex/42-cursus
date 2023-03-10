/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:33:56 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 13:51:29 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// penser a free en cas d'erreur 

t_var_env	*ft_new_env(char *name, char *value)
{
	t_var_env	*new;

	new = (t_var_env *)malloc(sizeof(t_var_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	if (!name || !value)
		return (NULL);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_envadd_front(t_var_env **lst, t_var_env *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->previous = new;
	}
	*lst = new;
}

void	ft_envadd_back(t_var_env **lst, t_var_env *new)
{
	t_var_env	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_envlast(*lst);
		last->next = new;
		new->previous = last;
	}
}

void	ft_free_env(t_var_env *lst)
{
	if (lst->name)
		free(lst->name);
	if (lst->value)
		free(lst->value);
	init_variables(lst);
}

void	ft_envremove(t_var_env *lst)
{
	if (!lst)
		return ;
	lst->previous->next = lst->next;
	lst->next->previous = lst->previous;
	ft_free_env(lst);
}
