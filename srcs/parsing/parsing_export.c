/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/26 11:45:04 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	nb_quotes(char *bloc)
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

char	*ft_protect_export_quotes(char *bloc, int i)
{
	char	*cpy;
	int		size;
	int		j;

	cpy = NULL;
	j = 0;
	size = ft_strlen2(bloc) + (nb_quotes(bloc) * 2);
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

