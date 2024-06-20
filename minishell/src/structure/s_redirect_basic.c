/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redirect_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:36:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 13:25:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	*s_redirect_acces_type(t_redirect *io)
{
	if (!io)
		return (NULL);
	return (&io->type);
}

char	*s_redirect_acces_arg(t_redirect *io)
{
	if (!io)
		return (NULL);
	return (io->arg);
}

t_redirect	*s_redirect_new(int type, char *arg)
{
	t_redirect	*new;

	new = ft_calloc(1, sizeof(t_redirect));
	if (!new)
		return (NULL);
	new->arg = ft_strndup(arg, ft_strlen2(arg));
	if (!new->arg)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	return (new);
}

void	s_redirect_del(void *addr)
{
	t_redirect	*io;

	io = addr;
	if (io->arg)
		free(io->arg);
	free(io);
}
