/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 18:38:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <termcap.h>

sig_atomic_t	g_status = 0;

/*	TODO: reset term state before exit	*/
void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

int	ft_tputchar(int n)
{
	char	c;

	c = n;
	return (write(1, &c, 1));
}

void	ft_init_term(char *data)
{
	char	*term;
	int		tget_status;

	term = getenv("TERM");
	if (!term)
		return ((void) ft_putendl_fd("Error : TERM not set", 2));
	tget_status = tgetent(data, term);
	if (tget_status == -1)
		return ((void) ft_putendl_fd("Error : could acces termcap database", \
			2));
	if (tget_status == 0)
		return ((void) ft_putendl_fd("Error : termcap database has too few info \
			or term is not in", 2));
}

void	ft_clear_term(void)
{
	char	*str;

	str = tgetstr("cl", NULL);
	tputs(str, 1, ft_tputchar);
	//free(str);
}



/*	TODO:	signal in here_doc and exe	*/
/*	TODO:	handle SHLVL	*/
/*	TODO:	listenv->char** func	*/
int	main(int ac, char **arg)
{
	char	*input;
	char	*buff;
	t_line	line;

	ft_sig_init(ft_sig_handler_shell);
	setup_term();
	s_init_line(&line);
	while (1)
	{
		g_status = READING;
		input = readline("Enter something : ");
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
			ft_clear_line_exit(&line, line.exit_status);
		//parsing(&cmdline, line);
		line.cmd = ft_calloc(1, sizeof(t_cmd));
		if (!line.cmd)
			return (ft_perror_return_int(NULL));
		s_init_cmd(line.cmd);
		line.cmd->arg = ft_split(input, ' ');
		if (!line.cmd->arg[0])
			line.n_cmds = 0;
		else
			line.n_cmds = 1;
		if (!ft_strncmp(input, "code", 5))
			printf("exit code is %d\n", line.exit_status);
		else if (!ft_strncmp(input, "here", 5) || !ft_strncmp(input, "\"here\"", 7))
		{
			printf("delimiter : %s\n", input);
			buff = ft_here_doc_mode(input);
			printf("here_doc :\n%s\n", buff);
			free(buff);
		}
		else//if (line.cmd->arg && line.cmd->arg[0])
			ft_exe_master(&line);
		ft_reset_line(&line);
		//if (g_status == SIGINT)
		//	g_status = 0;
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

valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --show-mismatched-frees=yes --read-var-info=yes

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