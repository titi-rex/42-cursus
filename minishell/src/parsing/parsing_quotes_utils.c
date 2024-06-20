/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:11:10 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/29 14:08:24 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_quotes_get_nb(char *bloc, int i, int nb)
{
	while (bloc[i])
	{
		if (bloc[i] == '\\')
			i += 2;
		if (bloc[i] == 34)
		{
			nb++;
			i++;
			while (bloc[i] && (bloc[i] != 34 || bloc[i - 1] == '\\'))
				i++;
			nb++;
		}
		if (bloc[i] == 39)
		{
			nb++;
			i++;
			while (bloc[i] && (bloc[i] != 39 || bloc[i - 1] == '\\'))
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
		while (bloc[*i] && (bloc[*i] != 34 || \
			(bloc[*i - 1] == '\\' && bloc[*i - 2] != '\\')))
		{
			(*cpy)[*j] = bloc[*i];
			(*j)++;
			(*i)++;
		}
		(*i)++;
	}
	else if (bloc[*i] == 39)
	{
		(*i)++;
		while (bloc[*i] && (bloc[*i] != 39 || \
			(bloc[*i - 1] == '\\' && bloc[*i - 2] != '\\')))
		{
			(*cpy)[*j] = bloc[*i];
			(*j)++;
			(*i)++;
		}
		(*i)++;
	}
}
