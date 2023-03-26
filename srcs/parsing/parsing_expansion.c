/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:36 by louisa            #+#    #+#             */
/*   Updated: 2023/03/26 11:50:37 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_get_expansion_value(char *bloc, t_line *line, int *len, int i)
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
	name = ft_substr(bloc, i, *len);
	if (!name)
		return (NULL);
	value = ft_strndup(get_value(line->lst_env, name), \
			ft_strlen2(get_value(line->lst_env, name)));
	free(name);
	return (value);
}

void	ft_exp_skip_quotes(char **bloc, int *i, t_line *line)
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
				*bloc = ft_replace_expansion_val(*bloc, line, 0, *i);
			(*i)++;
		}
	}
}

{
char	*ft_handle_expansion(char *bloc, t_line *line)
	int		i;

	i = 0;
	while (bloc[i])
	{
		ft_exp_skip_quotes(&bloc, &i, line);
		if (!bloc[i])
			break ;
		if (bloc[i] == 39)
		{
			i++;
			while ((bloc[i]) && bloc[i] != 39)
				i++;
		}
		if (bloc[i] && bloc[i] == '$' && bloc[i + 1] == '?')
			bloc = ft_replace_by_exit_status(bloc, i, line);
		if (bloc[i] && bloc[i] == '$')
		{
			bloc = ft_replace_expansion_val(bloc, line, 0, i);
            bloc = ft_protect_export_quotes(bloc, 0);
			i = -1;
		}
		i++;
	}
	return (bloc);
}

char	*ft_handle_expansion_hd(char *bloc, t_line *line)
{
	int		i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] && bloc[i] == '$' && bloc[i + 1] == '?')
			bloc = ft_replace_by_exit_status(bloc, i, line);
		if (bloc[i] && bloc[i] == '$')
		{
			bloc = ft_replace_expansion_val(bloc, line, 0, i);
			i = -1;
		}
		i++;
	}
	return (bloc);
}
