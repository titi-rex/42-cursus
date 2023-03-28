/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_var_env_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:50:31 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 20:03:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*s_env_last(t_var_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	s_env_add_back(t_var_env **lst, t_var_env *new)
{
	t_var_env	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = s_env_last(*lst);
		last->next = new;
		new->previous = last;
	}
}

void	s_env_clear(t_var_env **lst)
{
	t_var_env	*buff;

	if (!lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		s_env_del(*lst);
		*lst = buff;
	}
	lst = NULL;
}

int	s_env_size(t_var_env *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}
