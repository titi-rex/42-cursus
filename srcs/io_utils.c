/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:44:37 by louisa            #+#    #+#             */
/*   Updated: 2023/03/14 15:35:02 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// t'ass refait deux fonctions qui etaient deja dans s_redirect_basic
void	ft_free_io(t_redirect *lst)
{
	if (lst->arg)
		free(lst->arg);
	free(lst);
}

t_redirect	*ft_new_io(int type, int fd, char *arg)
{
	t_redirect	*new;

	new = (t_redirect *)malloc(sizeof(t_redirect));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->type = type;
	new->fd = fd;
	new->arg = ft_strndup(arg, ft_strlen2(arg));
	if (!new->arg)
	{
		ft_free_io(new);
		return (NULL);
	}
	return (new);
}