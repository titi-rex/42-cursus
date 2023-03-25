/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:20 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 19:27:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_handle_export(char *bloc, t_line *line)
{
	int	i;

	i = 0;
	while (bloc && bloc[i])
	{
		if (ft_strncmp(bloc, "export", 6) == 0)
		{
			bloc = ft_del_quotes(bloc, 0, 0);
			bloc = ft_handle_expansion(bloc, line);
			return (bloc);
		}
		i++;
	}
	return (bloc);
}
