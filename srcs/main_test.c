/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 00:22:27 by tlegrand         ###   ########.fr       */
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
	//ioctl(0, TCGETS, &t);
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
int	main(int ac, char **arg)
{
	char	*line;
	char	*data;
	//char	*tty;
	int		fd;

	fd = -1;
	data = NULL;

	ft_sig_init(ft_sig_handler_shell);
	ft_init_term(data);
	//setup_term();
	// tty = ttyname(STDIN_FILENO);
	// fd = open(tty, O_RDONLY | O_NDELAY);
	// if (fd == -1)
	// 	perror("Error ");
	// else
	// 	printf("tty name is %s\n", tty);
	// printf("isatty %d\n", isatty(ttyslot()));
	// printf("tty slot return %d\n", ttyslot());

	while (1)
	{
		line = readline("Enter something : ");
		if (line && line[0] != '\0')
			add_history(line);
		//else
		//	exit(0);
		//parsing(&cmdline, line);
		//ft_exe_master(&cmdline);
		//ft_reset_line(&cmdline);
		if (g_status == SIGINT)
			g_status = 0;
		if (!ft_strncmp(line, "clear", 6))
			ft_clear_term();
		if (!ft_strncmp(line, "exit", 5))
		{
			dprintf(1, "QUIT\n");
			if (fd != -1)
				close(fd);
			free(line);
			free(data);
			//ft_clear_line(&cmdline);
			//exit(cmdline.exit_sttaus);
			exit(0);
		}
		printf(":%s:\n", line);
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