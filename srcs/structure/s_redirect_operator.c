/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redirect_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:07:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 19:41:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ft_redirect_search_type(t_list *lst, int ref)
{
	while (lst)
	{
		if (*ft_redirect_acces_type(lst->content) == ref)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_redirect_add_list(t_list	**start, int type, int fd, char *arg)
{
	t_list		*new_node;
	t_redirect	*new_content;

	new_content = ft_redirect_new(type, fd, arg);
	if (!new_content)
		return (1);
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		ft_redirect_del(new_content);
		return (1);
	}
	ft_lstadd_back(start, new_node);
	return (0);
}

void	s_redirect_init(t_redirect *io)
{
	io->type = 0;
	io->fd = 0;
	io->arg = NULL;
}
