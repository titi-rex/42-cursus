/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 12:27:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	echo(char **arg)
{
	char	new_line;
	int		i;

	new_line = '\n';
	i = 1;
	if (!ft_strncmp(arg[1], "-n", 3))
	{
		new_line = '\0';
		i++;
	}
	printf("%s%c", arg[i], new_line);

	return (EXIT_SUCCESS);
}
