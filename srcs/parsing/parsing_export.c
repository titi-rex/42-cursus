/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/26 12:04:46 by louisa           ###   ########.fr       */
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
		if (bloc[i] == 39)
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_export_protect_quotes(char *bloc, int i)
{
	char	*cpy;
	int		size;
	int		j;

	cpy = NULL;
	j = 0;
	size = ft_strlen2(bloc) + (ft_export_nb_quotes(bloc) * 2);
	cpy = malloc((size + 1) * sizeof(int));
	if (!cpy)
		return NULL;
	while (bloc[i])
	{
		if (bloc[i] != 39)
			cpy[j] = bloc[i];
		if (bloc[i] == 39)
		{
			cpy[j] = 34;
			cpy[j + 1] = 39;
			cpy[j + 2] = 34;
			j += 2;
		}
		j++;
		i++;
	}
	return (cpy[j] = '\0', free(bloc), cpy);
}

