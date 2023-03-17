/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:50:31 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/16 16:12:16 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_variables(t_var_env *lst)
{
	lst->name = NULL;
	lst->value = NULL;
	lst->next = NULL;
	lst->previous = NULL;
}

t_var_env	*ft_envlast(t_var_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_envclear(t_var_env **lst)
{
	t_var_env	*buff;

	if (!lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		ft_free_env(*lst);
		*lst = buff;
	}
	lst = NULL;
}

void	change_value(t_var_env *lst, char *value, char *name)
{
	while (lst)
	{
		if (ft_strncmp(lst->name, name, ft_strlen2(name) + 1) == 0)
		{
			free(lst->value);
			lst->value = NULL;
			lst->value = ft_strdup(value);
			return ;
		}
		lst = lst->next;
	}
}

char	*get_value(t_var_env *lst, char *name)
{
	while (lst)
	{
		if (ft_strncmp(lst->name, name, ft_strlen2(name) + 1) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}
