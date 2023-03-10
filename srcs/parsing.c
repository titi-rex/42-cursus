/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:52:52 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 16:52:17 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		ft_free_env(new);
		return (NULL);
	}
	return (new);
}