/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/26 12:51:35 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export_nb_squotes(char *bloc)
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

int	ft_export_nb_dquotes(char *bloc)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (bloc[i])
	{
		if (bloc[i] == 34)
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_export_protect_dquotes(char *bloc, int i)
{
	char	*cpy;
	int		size;
	int		j;

	cpy = NULL;
	j = 0;
	size = ft_strlen2(bloc) + (ft_export_nb_dquotes(bloc) * 2);
	cpy = malloc((size + 1) * sizeof(int));
	if (!cpy)
		return NULL;
	while (bloc[i])
	{
		if (bloc[i] != 34)
			cpy[j] = bloc[i];
		if (bloc[i] == 34)
		{
			cpy[j] = 39;
			cpy[j + 1] = 34;
			cpy[j + 2] = 39;
			j += 2;
		}
		j++;
		i++;
	}
	return (cpy[j] = '\0', free(bloc), cpy);
}

char	*ft_export_protect_squotes(char *bloc, int i)
{
	char	*cpy;
	int		size;
	int		j;

	cpy = NULL;
	j = 0;
	size = ft_strlen2(bloc) + (ft_export_nb_squotes(bloc) * 2);
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


char	*ft_export_protect_quotes(char *bloc)
{
	int	i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] == 34)
		{
    		bloc = ft_export_protect_dquotes(bloc, 0);
			return (bloc);
		}
		else if (bloc[i] == 39)
		{
    		bloc = ft_export_protect_squotes(bloc, 0);
			return (bloc);
		}
		i++;
	}
    return (bloc);
}

