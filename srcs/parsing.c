/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/03/10 15:52:52 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/11 12:05:08 by lboudjem         ###   ########.fr       */
=======
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/10 15:23:10 by tlegrand         ###   ########.fr       */
>>>>>>> origin/execution2
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_handle_quotes(char *str, int i, int quote)
{
	i++;
	while (str[i])
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	ft_putstr_fd("Missing quote\n", 2);
	return (i);
}
<<<<<<< HEAD

void	ft_browse_line(char *str)
=======
/*
int	main(int argc, char **argv, char **env)
>>>>>>> origin/execution2
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			i = ft_handle_quotes(str, i, 34);
		if (str[i] == 39)
			i = ft_handle_quotes(str, i, 39);
		if (str[i] == '|')
			printf("pipe\n");
		if (str[i] == '\0')
			printf("endline\n");
		i++;
	}
}
*/