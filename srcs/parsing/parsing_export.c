/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/29 12:26:01 by lboudjem         ###   ########.fr       */
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

int	ft_export_nb_dolls(char *bloc)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (bloc[i])
	{
		if (bloc[i] == '$')
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
		return (perror("Error "), free(bloc), NULL);
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

char	*ft_export_protect_dolls(char *bloc)
{
	char	*cpy;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!bloc)
		return (NULL);
	size = ft_export_nb_dolls(bloc) + ft_strlen2(bloc);
	cpy = ft_calloc(size + 1, sizeof(int));
	if (!cpy)
		return (perror("Error "), free(bloc), NULL);
	while (bloc[++i])
	{
		if (bloc[i] == '$')
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
