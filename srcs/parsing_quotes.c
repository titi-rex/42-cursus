/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:10 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/14 15:43:06 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_quotes(char *str, int *i)
{
	if (str[*i] == 34)
		*i = ft_handle_quotes(str, *i, 34);
	if (str[*i] == 39)
		*i = ft_handle_quotes(str, *i, 39);
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

int	ft_handle_quotes(char *str, int i, int quote)
{
	i++;
	while (str[i])
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	ft_putstr_fd("Missing quote\n", 2);
	return (i);
}

char	*ft_delete_quotes(char *bloc, int size, int nb_quotes)
{
	char	*cpy;

	while (bloc[size])
	{
		if (bloc[size] == 34 || bloc[size] == 39)
			nb_quotes++;
		size++;
	}
	size -= nb_quotes;
	cpy = malloc(size * sizeof(char));
	if (!cpy)
		return (NULL);
	size = 0;
	nb_quotes = 0;
	while (bloc[size])
	{
		if (bloc[size] != 34 && bloc[size] != 39)
		{
			cpy[nb_quotes] = bloc[size];
			nb_quotes++;
		}
		size++;
	}
	cpy[nb_quotes - 1] = '\0';
	return (free(bloc), cpy);
}
