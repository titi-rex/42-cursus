/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 16:34:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_echo(char **arg)
{
	char	new_line;
	int		i;

	i = 1;
	new_line = '\n';
	if (!ft_strncmp(arg[1], "-n", 3))
	{
		new_line = '\0';
		i++;
	}
	if (printf("%s%c", arg[i], new_line) < 0)
	{
		perror("Error ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
