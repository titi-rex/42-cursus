/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:10 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 13:17:57 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_quotes(char *str, int *i, int *error)
{
	if (str[*i] == 34)
		*i = ft_handle_quotes(str, *i, 34, error);
	if (str[*i] == 39)
		*i = ft_handle_quotes(str, *i, 39, error);
}

int	ft_handle_quotes(char *str, int i, int quote, int *error)
{
	i++;
	while (str[i])
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	*error = 2;
	return (i);
}

int	get_nb_quotes(char *bloc, int i, int nb)
{
	while (bloc[i])
	{
		if (bloc[i] == 34)
		{
			nb++;
			i++;
			while (bloc[i] && bloc[i] != 34)
				i++;
			nb++;
		}
		if (bloc[i] == 39)
		{
			nb++;
			i++;
			while (bloc[i] && bloc[i] != 39)
				i++;
			nb++;
		}
		if (!bloc[i])
			return (-1);
		i++;
	}
	return (nb);
}

void	ft_skip_quotes(char *bloc, char **cpy, int *i, int *j)
{
	if (bloc[*i] == 34)
	{
		(*i)++;
		while (bloc[*i] && bloc[*i] != 34)
		{
			(*cpy)[*j] = bloc[*i];
			(*j)++;
			(*i)++;
		}
	}
	if (bloc[*i] == 39)
	{
		(*i)++;
		while (bloc[*i] && bloc[*i] != 39)
		{
			(*cpy)[*j] = bloc[*i];
			(*j)++;
			(*i)++;
		}
	}
}

char	*ft_del_quotes(char *bloc, int i, int j)
{
	char	*cpy;
	int		size;
	int		nb_quotes;

	nb_quotes = get_nb_quotes(bloc, 0, 0);
	size = ft_strlen2(bloc) - nb_quotes;
	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (bloc[i])
	{
		if (bloc[i] != 34 && bloc[i] != 39)
		{
			cpy[j] = bloc[i];
			j++;
		}
		ft_skip_quotes(bloc, &cpy, &i, &j);
		if (!bloc[i])
			return (NULL);
		i++;
	}
	cpy[j] = '\0';
	free(bloc);
	return (cpy);
}
