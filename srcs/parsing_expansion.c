/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:36 by louisa            #+#    #+#             */
/*   Updated: 2023/03/14 14:43:32 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// free dans les cas d'erreur 
// handle expansion si pas de pipe apres
// echo $SHELL $HSELL $SHELL | 'echo $SHELL' | "echo $SHELL | coucou"
// echo $SHELL $HSELL $SHELL | 'echo $SHELL' | "echo $SHELL" | coucou
// -> probleme de fsanitize (heap buffer overflow")

char	*ft_get_expansion_value(char *bloc, t_line *line, int *len, int i)
{
	char	*name;
	char	*value;
	int		tmp;

	tmp = i;
	while (bloc[tmp] != ' ' && bloc[tmp] != 34)
	{
		tmp++;
		(*len)++;
	}
	name = malloc((*len + 1) * sizeof(char));
	if (!name)
		return (NULL);
	name = ft_substr(bloc, i, *len);// pas besoin de malloc avant un substr
	if (!name)
		return (NULL);
	value = ft_strndup(get_value(line->lst_env, name), ft_strlen2(get_value(line->lst_env, name)));
	if (!value) // si la variable n existe pas pas d erreur remplacer par rien (effacer le $NAME)
	{
		printf("This variable does not exist\n");
		return (NULL);
	}
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
	// else
	// 	cpy[i++] = "";
	while (bloc[tmp])
		cpy[i++] = bloc[tmp++];
	cpy[i] = '\0';
	free(bloc);
	return(cpy);
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
		return (free(exit_s), NULL); //pas besoin de free so exit_s deja null
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

void	ft_handle_expansion(char **bloc, t_line *line)
{
	int		i;

	i = 0;
	while ((*bloc)[i])
	{
		if ((*bloc)[i] == 39)
		{
			i++;
			while ((*bloc)[i] != 39)
				i++;
		}
		if ((*bloc)[i] == '$' && (*bloc)[i + 1] == '?')
			*bloc = ft_replace_by_exit_status(*bloc, i, line);
		if ((*bloc)[i] == '$')
		{
			*bloc = ft_replace_expansion_value(*bloc, line, 0, i);
			i++;
			if (!(*bloc)[i])
				break ;
		}
		i++;
	}
}