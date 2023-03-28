/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redirect_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:07:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 21:30:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*s_redirect_search_type(t_list *lst, int ref)
{
	while (lst)
	{
		if (*s_redirect_acces_type(lst->content) == ref)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	s_redirect_add_list(t_list	**start, int type, char *arg)
{
	t_list		*new_node;
	t_redirect	*new_content;

	new_content = s_redirect_new(type, arg);
	if (!new_content)
		return (1);
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		s_redirect_del(new_content);
		return (1);
	}
	ft_lstadd_back(start, new_node);
	if (arg)
		free(arg);
	return (0);
}

void	s_redirect_init(t_redirect *io)
{
	io->type = 0;
	io->arg = NULL;
}
