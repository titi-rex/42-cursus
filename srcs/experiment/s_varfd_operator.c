/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_varfd_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:30:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 21:57:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ft_varfd_search(t_list *lst, char *name)
{
	int	n;

	if (!name)
		return (NULL);
	n = ft_strlen(name);
	while (lst)
	{
		if (!ft_strncmp(ft_varfd_acces_varname(lst->content), name, n))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_varfd_get_value_from_key(t_line *line, char *name)
{
	t_list	*tmp;
	t_varfd	*new;

	tmp = ft_varfd_search(line->lst_varfd, name);
	if (tmp)
		return (*ft_varfd_acces_fd(tmp->content));
	new = ft_varfd_new(name, line->fdcount);
	if (!new)
		return (-1);
	tmp = ft_lstnew((void *) new);
	if (!tmp)
	{
		ft_varfd_del(new);
		return (-1);
	}
	line->fdcount++;
	ft_lstadd_back(&line->lst_varfd, tmp);
	return (*ft_varfd_acces_fd(tmp->content));
}
