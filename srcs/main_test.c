/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/15 15:48:28 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	g_sig = 0;

// int	main(int ac, char **arg)
// {
// 	ft_sig_launch();

// 	while (1)
// 	{
// 		if (g_sig == SIGINT)
// 		{
// 			dprintf(1, "g_sig update : %d\n", g_sig);
// 			g_sig = 0;
// 		}
// 		if (g_sig == SIGQUIT)
// 		{
// 			dprintf(2, "he heo stop\n");
// 			g_sig = 0;
// 		}
// 	}

// 	(void) arg;
// 	(void) ac;
// 	return (0);
// }

/*
ctrl c = SIGINT (new prompt new line)
ctrl d = send OEF NOT A SIGNAL close terminal (exit)
ctrl \ = SIGQUIT (rompish)

ctrl z = SIGSTP (freeze)

valgrind
--suppressions=valgrind_ignore_leaks.txt
--leak-check=full --show-leak-kinds=all
--track-origins=yes --verbose
--show-mismatched-frees=yes
--read-var-info=yes

(option) --log-file=valgrind-out.txt

valgrind_ignore_leaks.txt :
{
	leak readline
	Memcheck:Leak
	...
	fun:readline
}
{
	leak add_history
	Memcheck:Leak
	...
	fun:add_history
}
*/

/*
	//t_cmd	cmd;
	int		i;

	// s_init_cmd(&cmd);
	// cmd.arg = ft_calloc(ac, sizeof(void *));
	// i = 0;
	// while (i < ac - 1)
	// {
	// 	cmd.arg[i] = ft_strdup(arg[i + 1]);
	// 	i++;
	// }
*/