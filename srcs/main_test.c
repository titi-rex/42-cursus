/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 22:09:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **arg)
{
	t_line	line;
	t_cmd	cmd;
	int		i;

	s_init_cmd(&cmd);
	cmd.arg = ft_calloc(ac, sizeof(void *));
	i = 0;
	while (i < ac - 1)
	{
		cmd.arg[i] = ft_strdup(arg[i + 1]);
		i++;
	}
	s_init_line(&line);
	line.cmd = &cmd;
	line.n_cmds = 1;
	ft_exe_master(&line);
	ft_clear_line_exit(&line, line.exit_status);
	(void) arg;
	(void) ac;
	return (0);
}

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