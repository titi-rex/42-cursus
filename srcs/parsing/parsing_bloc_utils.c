/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:59:18 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/27 15:10:58 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_bloc_empty(char *bloc)
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

void	ft_bloc_init(t_list **io, int *error, char **bloc)
{
	*io = NULL;
	*bloc = NULL;
	*error = 0;
}

int	ft_bloc_separate(char **str, int *i, int *start, char **bloc)
{
	int	nb_cmds;

	nb_cmds = 0;
	if ((*str)[*i] == '|')
	{
		*bloc = ft_bloc_creat(*str, i, start, *bloc);
		nb_cmds++;
	}
	else if ((*str)[*i] == '\0' || (*str)[(*i) + 1] == '\0')
	{
		*bloc = ft_substr(*str, *start, ((*i) + 1) - *start);
		nb_cmds++;
	}
	return (nb_cmds);
}

void	ft_bloc_format(char **bloc, t_list **io, int *error, t_line *line)
{
	*bloc = ft_bloc_protect_backslash(*bloc);
	*bloc = ft_exp_handle(*bloc, line);
	*io = ft_redirection_handle(bloc, error, line, 0);
}
