/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:59:18 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/29 12:47:41 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_bloc_empty(char *bloc)
{
	int	i;

	i = 0;
	if (bloc[0] == '\0')
		return (2);
	while (bloc[i])
	{
		if (bloc[i] != ' ' && bloc[i] != '\t' && \
			bloc[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_bloc_init(t_list **io, int *error, char **bloc)
{
	*io = NULL;
	*bloc = NULL;
	error[0] = 0;
	error[1] = 0;
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
	if (!*bloc)
		return ;
	*bloc = ft_bloc_protect_backslash(*bloc);
	if (!*bloc)
		return ;
	*io = ft_redirection_handle(bloc, error, line, 0);
	*bloc = ft_exp_handle(*bloc, line, 0);
	if (!*bloc)
		return ;
}

void	ft_bloc_cmd_free(char **split, int i)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (j == i)
			j++;
		if (split[j])
			free(split[j]);
		if (split[j])
			j++;
	}
	free(split);
}
