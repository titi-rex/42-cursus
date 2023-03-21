/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:10 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:06 by lboudjem         ###   ########.fr       */
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

char	*ft_creat_bloc(char *str, int *i, int *start, char *bloc)
{
	bloc = ft_substr(str, *start, *i - *start);
	*start = *i;
	while (str[*start] != '|')
		(*start)++;
	(*start)++;
	while (str[*start] == ' ')
		(*start)++;
	return (bloc);
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

char	*ft_delete_quotes(char *bloc, int size, int nb_quotes, char quote)
{
	char	*cpy;

	while (bloc[size])
	{
		if (bloc[size] == quote)
			nb_quotes++;
		size++;
	}
	size -= nb_quotes;
	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	size = 0;
	nb_quotes = 0;
	while (bloc[size])
	{
		if (bloc[size] != quote)
		{
			cpy[nb_quotes] = bloc[size];
			nb_quotes++;
		}
		size++;
	}
	cpy[nb_quotes] = '\0';
	return (free(bloc), cpy);
}

int	get_nb_quotes(char *bloc, int i)
{
	int	nb;

	nb = 0;
	while (bloc[i])
	{
		if (bloc[i] == 34)
		{
			nb++;
			i++;
			while (bloc[i] != 34)
				i++;
			nb++;
		}
		if (bloc[i] == 39)
		{
			nb++;
			i++;
			while (bloc[i] != 39)
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

char	*ft_del_quotes(char *bloc)
{
	char	*cpy;
	int		size;
	int		nb_quotes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_quotes = get_nb_quotes(bloc, 0);
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
		if (bloc[i] == 34)
		{
			i++;
			while (bloc[i] != 34)
			{
				cpy[j] = bloc[i];
				j++;
				i++;
			}
		}
		if (bloc[i] == 39)
		{
			i++;
			while (bloc[i] != 39)
			{
				cpy[j] = bloc[i];
				j++;
				i++;
			}
		}
		i++;
	}
	cpy[j] = '\0';
	free(bloc);
	return (cpy);
}
