/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 13:07:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* TODO: free arg before exit ? */
int	echo(char **arg)
{
	char	new_line;
	int		i;
	int		err;

	i = 1;
	new_line = '\n';
	err = EXIT_SUCCESS;
	if (!ft_strncmp(arg[1], "-n", 3))
	{
		new_line = '\0';
		i++;
	}
	if (printf("%s%c", arg[i], new_line) < 0)
		err = EXIT_FAILURE;
	//ft_free2d((void **) arg, 0);
	exit(err);
}
