/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_varfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 22:26:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	open pipe to mimic bash ?? */
t_varfd	*s_new_varfd(char *varname, int fdcount)
{
	t_varfd	*new;

	new = ft_calloc(1, sizeof(t_varfd));
	if (!new)
		return (NULL);
	new->varname = ft_strdup(varname);
	if (!new->varname)
	{
		free(new);
		return (NULL);
	}
	new->fd = 10 + fdcount;
	new->next = NULL;
	return (new);
}
