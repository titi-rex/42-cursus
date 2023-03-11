/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:52:52 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/11 12:05:08 by lboudjem         ###   ########.fr       */
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

void	ft_browse_line(char *str)
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
