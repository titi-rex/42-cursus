/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redirect_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:36:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/16 14:51:45 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	*ft_redirect_acces_type(t_redirect *io)
{
	if (!io)
		return (NULL);
	return (&io->type);
} 

char	*ft_redirect_acces_arg(t_redirect *io)
{
	if (!io)
		return (NULL);
	return (io->arg);
}

t_redirect	*ft_redirect_new(int type, char *arg)
{
	t_redirect	*new;

	new = ft_calloc(1, sizeof(t_redirect));
	if (!new)
		return (NULL);
	new->arg = ft_strdup(arg);
	if (!new->arg)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	return (new);
}

void	ft_redirect_del(void *addr)
{
	t_redirect	*io;

	io = addr;
	if (io->arg)
		free(io->arg);
	free(io);
}
