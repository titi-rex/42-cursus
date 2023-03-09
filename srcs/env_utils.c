/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:33:56 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/09 16:45:02 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*ft_new_env(char *name, char *value)
{
	t_var_env	*new;

	new = (t_var_env *)malloc(sizeof(t_var_env));
	if (!new)
		return (NULL);
	new->name = malloc(sizeof(char) * ft_strlen(name));
	if (!new->name)
		return (NULL);
	new->value = malloc(sizeof(char) * ft_strlen(value));
	if (!new->value)
		return (NULL);
	new->name = name;
	new->value = value;
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
