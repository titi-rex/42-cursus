/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_protect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:04:15 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/28 12:26:35 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_bloc_nb_backslash(char *bloc)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (bloc[i])
	{
		if (bloc[i] == '\\' && bloc[i + 1] != '\\')
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_bloc_clear_backslash(char *bloc)
{
	char	*cpy;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	cpy = NULL;
	size = ft_strlen2(bloc) - (ft_bloc_nb_backslash(bloc));
	cpy = ft_calloc((size + 1), sizeof(int));
	if (!cpy)
		return (NULL);
	while (bloc && bloc[++i])
	{
		if (bloc[i] != '\\')
			cpy[j] = bloc[i];
		else if (bloc[i] == '\\')
			cpy[j] = bloc[++i];
		j++;
	}
	return (free(bloc), cpy);
}

char	*ft_bloc_protect_backslash(char *bloc)
{
	char	*cpy;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	cpy = NULL;
	size = ft_bloc_nb_backslash(bloc) + ft_strlen2(bloc);
	cpy = ft_calloc((size + 1), sizeof(int));
	if (!cpy)
		return (NULL);
	while (bloc[++i])
	{
		if (bloc[i] != '\\')
			cpy[j] = bloc[i];
		else if (bloc[i] == '\\')
		{
			cpy[j] = '\\';
			j++;
			cpy[j] = '\\';
		}
		j++;
	}
	return (free(bloc), cpy);
}
