/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/21 10:33:28 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_handle_export(char *bloc)
{
	int	i;

	i = 0;
	while (bloc[i])
	{
		if(ft_strncmp(bloc, "export", 6) == 0)
		{
			i += 6;
			while (bloc[i] && (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n'))
				i++;
			while (bloc[i] && (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n'))
			{
				if (bloc[i] == '=')
					bloc[i] = ' ';
				i++;
			}
		}
		i++;
	}
	return (bloc);
}