/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/24 13:10:07 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_size_export(char *bloc)
{
	int		i;

	i = 6;
	while (bloc[i] && (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n'))
		i++;
	while (bloc[i] && bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n')
		i++;
	return (i);
}

char	*ft_format_export(char *bloc, int size)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = malloc((size + 1) * sizeof(char));
	while (bloc[i])
	{
		while (bloc[i] && bloc[i] != '=')
		{
			cpy[j] = bloc[i];
			j++;
			i++;
		}
		if (cpy[j] && bloc[i] && bloc[i] == '=')
		{
			cpy[j] = ' ';
			cpy[j + 1] = '=';
			cpy[j + 2] = ' ';
			j += 3;
		}
		if (!bloc[i])
			break ;
		i++;
	}
	cpy[j] = '\0';
	free(bloc);
	return (cpy);
}

char	*ft_handle_export(char *bloc)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	if (ft_strncmp(bloc, "export", 6) == 0 && bloc[6] == 32)
	{
		i = ft_size_export(bloc);
		cpy = ft_substr(bloc, 0, i);
		cpy = ft_format_export(bloc, i + 2);
		return (cpy);
	}
	return (bloc);
}

// char	*ft_handle_export(char *bloc)
// {
// 	int	i;

// 	i = 0;
// 	while (bloc && bloc[i])
// 	{
// 		if (ft_strncmp(bloc, "export", 6) == 0)
// 		{
// 			i += 6;
// 			while (bloc[i] && (bloc[i] == ' ' || bloc[i] == '\t' 
// 				|| bloc[i] == '\n'))
// 				i++;
// 			while (bloc[i] && (bloc[i] != ' ' && bloc[i] != '\t' 
// 				&& bloc[i] != '\n'))
// 			{
// 				if (bloc[i] == '=')
// 					bloc[i] = ' ';
// 				i++;
// 			}
// 			if (!bloc[i])
// 				break ;
// 		}
// 		i++;
// 	}
// 	return (bloc);
// }
