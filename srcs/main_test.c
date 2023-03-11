/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/11 15:18:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **arg)
{
	t_line		line;
	t_list		*io;
	t_list		*new_l;
	t_redirect	*new_red;
	char		*tmp;
	char		**split;
	int			i;

	tmp = NULL;
	chdir(tmp);
	perror("Error ");
	exit(1);
	s_init_line(&line);
	line.n_cmds = 1;
	line.lst_varfd = NULL;
	new_red = ft_redirect_new(0, 0, "test");
	if (!new_red)
		return (1);
	new_l = ft_lstnew(new_red);
	if (!new_l)
		return (1);
	ft_lstadd_back(&io, new_l);
	printf("io : %d, %d, %s\n", *ft_redirect_acces_type(io->content), \
		*ft_redirect_acces_fd(io->content), \
		ft_redirect_acces_arg(io->content));
	//printf("io ad : %p\n", io);
	//printf("io->next ad : %p\n", io->next);
	split = ft_calloc(ac, sizeof(void *));
	i = 0;
	while (i < ac - 1)
	{
		split[i] = ft_strdup(arg[i + 1]);
		i++;
	}
	line.cmd = ft_cmd_new_alloc(split, io);


	ft_exe_master(&line);
	//ft_clear_line(&line);
	//ft_clear_line_exit(&line, line.exit_status);
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