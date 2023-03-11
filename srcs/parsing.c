/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:52:52 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 22:06:49 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_handle_quotes(char *str, int *inv_pipe, int i, int quote)
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
	(void)inv_pipe;
}

void	ft_browse_line(char *str)
{
	int	i;
	int	*inv_pipe = NULL;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			i = ft_handle_quotes(str, inv_pipe, i, 34);
		if (str[i] == 39)
			i = ft_handle_quotes(str, inv_pipe, i, 39);
		if (str[i] == '|')
			printf("pipe\n");
		if (str[i] == '\0')
			printf("endline\n");
		i++;
	}
}
