/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:43:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 15:48:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief print arg (DEBUG ONLY)
 * 
 * @param arg 
 */
void	debug_print_cmd_arg(char **arg)
{
	int	i;

	if (!arg)
		return ((void)ft_putstr_fd("arg NULL\n", 2));
	i = -1;
	while (arg[++i])
		printf("arg[%d] = :%s:\n", i, arg[i]);
	printf("last : arg[%d] = :%s:\n", i, arg[i]);
}

/**
 * @brief print env (DEBUG ONLY)
 * 
 * @param lst 
 */
void	debug_print_env(t_var_env	*lst)
{
	while (lst)
	{
		printf("%s=%s\n", lst->name, lst->value);
		lst = lst->next;
	}
}

/**
 * @brief print term c_flag (DEBUG ONLY)
 * 
 */
void	debug_term_status(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	dprintf(2, " cflag check:%d:\n", t.c_lflag);
}
