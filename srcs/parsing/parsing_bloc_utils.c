/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:59:18 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 19:01:52 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_bloc_empty(char *bloc)
{
	int	i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] != ' ' && bloc[i] != '\t' && \
			bloc[i] != '\n' && bloc[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	init_bloc(t_list **io, int *error, char **bloc)
{
	*io = NULL;
	*bloc = NULL;
	*error = 0;
}

int	separate_bloc(char **str, int *i, int *start, char **bloc)
{
	int	nb_cmds;

	nb_cmds = 0;
	if ((*str)[*i] == '|')
	{
		*bloc = ft_creat_bloc(*str, i, start, *bloc);
		nb_cmds++;
	}
	else if ((*str)[*i] == '\0' || (*str)[(*i) + 1] == '\0')
	{
		*bloc = ft_substr(*str, *start, ((*i) + 1) - *start);
		nb_cmds++;
	}
	return (nb_cmds);
}

void	format_bloc(char **bloc, t_list **io, int *error, t_line *line)
{
	*bloc = ft_handle_expansion(*bloc, line);
	*io = ft_handle_redirection(bloc, error, line);
	*bloc = ft_handle_export(*bloc, line);
    // fct qui protege les simples quotes
}
