/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:48 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 16:15:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*ft_env_search(t_var_env *lst, char *name)
{
	while (lst)
	{
		if (!ft_strncmp(lst->name, name, ft_strlen2(name) + 1))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char	**ft_env_lst_to_tab(t_var_env *lst)
{
	char	**tab;
	int		i;

	if (!lst)
		return (NULL);
	tab = ft_calloc(s_env_size(lst), sizeof(t_var_env));
	if (!tab)
		return (perror("Error "), NULL);
	i = 0;
	while (lst)
	{
		if (lst->value)
		{
			tab[i] = ft_strjoin3(lst->name, "=", lst->value);
			if (!tab)
			{
				ft_free2d((void **)tab, 0);
				return (perror("Error "), NULL);
			}
			i++;
		}
		lst = lst->next;
	}
	return (tab);
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
