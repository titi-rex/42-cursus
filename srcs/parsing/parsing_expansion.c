/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:36 by louisa            #+#    #+#             */
/*   Updated: 2023/03/17 16:21:28 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// free dans les cas d'erreur 

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

char	*ft_replace_expansion_value(char *bloc, t_line *line, int len, int i)
{
	char	*value;
	char	*cpy;
	int		size;
	int		tmp;

	value = ft_get_expansion_value(bloc, line, &len, i + 1);
	size = ft_strlen2(bloc) - len + ft_strlen2(value);
	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	tmp = i + len + 1;
	ft_strlcpy(cpy, bloc, i + 1);
	size = 0;
	if (value)
		while (value[size])
			cpy[i++] = value[size++];
	while (bloc && bloc[tmp])
		cpy[i++] = bloc[tmp++];
	cpy[i] = '\0';
	free(bloc);
	return (cpy);
}

char	*ft_replace_by_exit_status(char *bloc, int i, t_line *line)
{
	char	*exit_s;
	char	*cpy;
	int		len;
	int		tmp;

	tmp = i + 2;
	exit_s = ft_itoa(line->exit_status);
	if (!exit_s)
		return (NULL);
	len = (int)(ft_strlen2(bloc)) - 2 + ft_strlen2(exit_s);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, bloc, i + 1);
	len = 0;
	while (exit_s[len])
		cpy[i++] = exit_s[len++];
	while (bloc[tmp])
		cpy[i++] = bloc[tmp++];
	cpy[i] = '\0';
	free(bloc);
	return (free(exit_s), cpy);
}

char	*ft_handle_expansion(char *bloc, t_line *line)
{
	int		i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] == 34)
		{
			i++;
			while ((bloc[i]) && bloc[i] != 34)
			{
				if (bloc[i] && bloc[i] == '$')
					bloc = ft_replace_expansion_value(bloc, line, 0, i);
				i++;
			}
		}
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
			bloc = ft_replace_expansion_value(bloc, line, 0, i);
			i = -1;
		}
		i++;
	}
	return (bloc);
}
