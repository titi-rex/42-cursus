/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:50:31 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/27 14:11:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_var_env_init(t_var_env *lst)
{
	lst->name = NULL;
	lst->value = NULL;
	lst->next = NULL;
	lst->previous = NULL;
}

t_var_env	*ft_env_last(t_var_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_env_clear(t_var_env **lst)
{
	t_var_env	*buff;

	if (!lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		ft_env_free(*lst);
		*lst = buff;
	}
	lst = NULL;
}

void	ft_env_change_value(t_var_env *lst, char *value, char *name)
{
	while (lst)
	{
		if (ft_strncmp(lst->name, name, ft_strlen2(name) + 1) == 0)
		{
			free(lst->value);
			lst->value = NULL;
			lst->value = ft_strndup(value, ft_strlen2(value));
			return ;
		}
		lst = lst->next;
	}
}

char	*ft_env_get_value(t_var_env *lst, char *name)
{
	while (lst)
	{
		if (ft_strncmp(lst->name, name, ft_strlen2(name) + 1) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}
