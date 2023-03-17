/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:02 by louisa            #+#    #+#             */
/*   Updated: 2023/03/16 16:21:33 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_redirection_arg(char *bloc, int i)
{
	int		len;
	int		tmp;
	char	*arg;

	len = 0;
	while (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n' \
			|| bloc[i] == '>' || bloc[i] == '<')
		i++;
	tmp = i;
	if (!bloc[i])
		return (NULL);
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	arg = ft_substr(bloc, tmp, len);
	return (arg);
}

int	ft_redirection_type_fd(char *bloc, int *type, int *i)
{
	if (bloc[*i] == '<')
	{
		*type = 0;
		return (1);
	}
	if (bloc[*i] == '>')
	{
		*type = 1;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], "<<", 2) == 0)
	{
		*type = 2;
		(*i)++;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], ">>", 2) == 0)
	{
		*type = 3;
		(*i)++;
		return (1);
	}
	return (0);
}

t_list	*ft_handle_redirection(char *bloc, int *error)
{
	int			i;
	int			type;
	char		*arg;
	t_list		*io;

	i = 0;
	type = -1;
	io = NULL;
	arg = NULL;
	while (bloc[i])
	{
		if (ft_redirection_type_fd(bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(bloc, i);
			if (!arg)
				return (*error = 1, NULL);
			ft_redirect_add_list(&io, type, arg);
			free(arg);
			i++;
		}
		i++;
	}
	return (*error = 0, io);
}
