/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:10 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/29 11:24:32 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_quotes_error(char *str, int *i, int *error)
{
	if (str[*i] == 34)
		*i = ft_quotes_handle(str, *i, 34, error);
	if (str[*i] == 39)
		*i = ft_quotes_handle(str, *i, 39, error);
	return (*error);
}

int	ft_quotes_handle(char *str, int i, int quote, int *error)
{
	i++;
	while (str[i])
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	*error = 3;
	return (i);
}

char	*ft_quotes_delete_secure(char *bloc, int i, int j)
{
	char	*cpy;
	int		size;

	if (!bloc)
		return (NULL);
	size = ft_strlen2(bloc) - ft_quotes_get_nb(bloc, 0, 0);
	cpy = ft_calloc((size + 1), sizeof(char));
	if (!cpy)
		return (ft_free_secure(bloc), NULL);
	while (bloc[i])
	{
		if (bloc[i] == '\\')
		{
			cpy[j++] = bloc[i++];
			cpy[j++] = bloc[i++];
		}
		else if (bloc[i] != 34 && bloc[i] != 39)
			cpy[j++] = bloc[i++];

		else if (bloc[i] == 34 || bloc[i] == 39)
			ft_skip_quotes(bloc, &cpy, &i, &j);
		if (!bloc[i - 1] || !bloc[i])
			break ;
	}
	return (ft_free_secure(bloc), cpy);
}

char	*ft_quotes_delete(char *bloc, int i, int j)
{
	int	tmp;
	int	quote;

	tmp = 0;
	quote = 0;
	while (bloc[tmp])
	{
		if (bloc[tmp] == 34 || bloc[tmp] == 39)
			quote = 1;
		tmp++;
	}
	if (quote == 1)
		bloc = ft_quotes_delete_secure(bloc, i, j);
	return (bloc);
}
