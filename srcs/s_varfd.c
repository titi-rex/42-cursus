/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_varfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 16:45:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	open pipe to mimic bash ?? */
t_varfd	*ft_varfd_new(char *varname, int fdcount)
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
	return (new);
}

int	bi_add_env(t_line *line)
{
	ft_add_env(line->cmd->arg[0], line->cmd->arg[1]);
}

int	s_varfd_get(t_line *line, char *name)
{
	t_varfd	*tmp;
	t_list	*new;

	tmp = ft_varfd_search(line->lst_varfd, name);
	if (tmp)
		return (tmp->fd);
	tmp = ft_varfd_new(name, line->fdcount);
	if (!tmp)
		return (-1);
	new = ft_lstnew((void *) tmp);
	if (!new)
	{
		ft_clear_varfd(tmp);
		return (-1);
	}
	ft_lstadd_back(line->lst_varfd, new);
	return (new->fd);
}
