/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 12:26:45 by lboudjem         ###   ########.fr       */
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

	i = 0;
	j = 0;
	size = ft_export_nb_quotes(bloc) + ft_strlen2(bloc);
	cpy = ft_calloc(size + 1, sizeof(int));
	if (!cpy)
		return (NULL);
	while (bloc[i])
	{
		if (bloc[i] == 34 || bloc[i] == 39)
		{
			cpy[j++] = '\\';
			cpy[j] = bloc[i];
		}
		else
			cpy[j] = bloc[i];
		j++;
		i++;
	}
	return (free(bloc), cpy);
}
