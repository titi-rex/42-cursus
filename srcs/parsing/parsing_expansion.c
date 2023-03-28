/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:36 by louisa            #+#    #+#             */
/*   Updated: 2023/03/28 12:27:38 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_exp_get_value(char *bloc, t_line *line, int *len, int i)
{
	char	*name;
	char	*value;
	int		tmp;

	tmp = i;
	if (!bloc && !bloc[tmp])
		return (NULL);
	while (bloc[tmp] && (bloc[tmp] == '_' || ft_isalnum(bloc[tmp]) != 0) \
			&& bloc[tmp] != 34 && bloc[tmp] != 39)
	{
		tmp++;
		(*len)++;
	}
	if (ft_isdigit(bloc[i]))
		(*len) = 1;
	name = ft_substr(bloc, i, *len);
	if (!name)
		return (NULL);
	value = ft_strndup(ft_env_get_value(line->lst_env, name), \
			ft_strlen2(ft_env_get_value(line->lst_env, name)));
	free(name);
	return (value);
}

void	ft_exp_skip_quote(char **bloc, int *i, t_line *line)
{
	if ((*bloc)[*i] == 34)
	{
		(*i)++;
		while (((*bloc)[*i]) && (*bloc)[*i] != 34)
		{
			if ((*bloc)[*i] && (*bloc)[*i] == '$' \
				&& ft_isalnum((*bloc)[(*i) + 1]) == 0)
				(*i)++;
			if ((*bloc)[*i] && (*bloc)[*i] == '$')
				*bloc = ft_exp_replace_value(*bloc, line, 0, *i);
			(*i)++;
		}
	}
}

char	*ft_exp_handle(char *bloc, t_line *line, int i)
{
	while (bloc[i])
	{
		ft_exp_skip_quote(&bloc, &i, line);
		if (!bloc[i])
			break ;
		if (bloc[i] == 39)
		{
			i++;
			while ((bloc[i]) && bloc[i] != 39)
				i++;
		}
		if (bloc[i] && bloc[i] == '$' && ft_isalnum(bloc[i + 1]) == 0)
			break ;
		else if (bloc[i] && bloc[i] == '$' && bloc[i + 1] == '?')
			bloc = ft_exp_replace_exit_status(bloc, i, line);
		else if (bloc[i] && bloc[i] == '$')
		{
			bloc = ft_exp_replace_value(bloc, line, 0, i);
			i = -1;
		}
		i++;
	}
	return (bloc);
}

char	*ft_exp_handle_heredoc(char *bloc, t_line *line)
{
	int		i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] && bloc[i] == '$' && bloc[i + 1] == '?')
			bloc = ft_exp_replace_exit_status(bloc, i, line);
		if (bloc[i] && bloc[i] == '$')
		{
			bloc = ft_exp_replace_value(bloc, line, 0, i);
			i = -1;
		}
		i++;
	}
	return (bloc);
}
