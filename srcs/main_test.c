/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/12 00:21:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

sig_atomic_t	g_status = 0;


void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

/*	TODO:	signal in here_doc and exe	*/
/*	TODO:	handle SHLVL	*/
int	main(int ac, char **arg)
{
	char	*line;

	ft_sig_init(ft_sig_handler_shell);
	setup_term();
	while (1)
	{
		line = readline("Enter something : ");
		if (line && line[0] != '\0')
			add_history(line);
		else
			exit(0);
		//parsing(&cmdline, line);
		//ft_exe_master(&cmdline);
		//ft_reset_line(&cmdline);
		if (g_status == SIGINT)
			g_status = 0;
		if (!ft_strncmp(line, "exit", 5))
		{
			dprintf(1, "QUIT\n");
			free(line);
			//ft_clear_line(&cmdline);
			//exit(cmdline.exit_sttaus);
			exit(0);
		}
		//printf(":%s:\n", line);
	}
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