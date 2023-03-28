/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 15:13:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export_nb_quotes(char *bloc)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (bloc[i])
	{
		if (bloc[i] == 39 || bloc[i] == 34)
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_export_protect_quotes(char *bloc)
{
	char	*cpy;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!bloc)
		return (NULL);
	size = ft_export_nb_quotes(bloc) + ft_strlen2(bloc);
	cpy = ft_calloc(size + 1, sizeof(int));
	if (!cpy)
		return (free(bloc), NULL);
	while (bloc[++i])
	{
		if (bloc[i] == 34 || bloc[i] == 39)
		{
			cpy[j++] = '\\';
			cpy[j] = bloc[i];
		}
		else
			cpy[j] = bloc[i];
		j++;
	}
	return (free(bloc), cpy);
}
