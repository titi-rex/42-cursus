/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redirect_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:07:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 22:27:56 by tlegrand         ###   ########.fr       */
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
