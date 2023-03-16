/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/16 17:23:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

sig_atomic_t	g_status = 0;

/*
PWD
time
user
exit status 
machine
TIME_UTC
*/

void	ft_init_main(t_line *line, char **env)
{
	ft_sig_init(ft_sig_handler_shell);
	term_init_setting(&line->old);
	s_line_init(line);
	//line->lst_env = fill_lst_env2(env);
	ft_var_env_update_shlvl(line->lst_env);
	(void)env;
}

/*	FIXME:	exit qui print exit mais jsp ou */
/*	TODO:	prompt function */
/*	TODO:	man/greeting function */
/*	TODO:	update redirect without fd -> update dup redirect*/
/*	TODO:	gestion arg for minishell ? + error	*/
/*	TODO: mettre au propre	*/
/*	TODO:FIXME:	minishell > log need to display prompt */
int	fmain(int ac, char **arg, char **env)
{
	char	*input;
	// char	*prompt;
	t_line	line;

	if (ac != 1)
		return (1);
	ft_init_main(&line, env);
	//prompt = ft_get_a_nice_prompt(line.lst_env);
	while (1)
	{
		g_status = READING;
		input = readline("Enter something : ");
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
			ft_clean_exit(&line, line.exit_status);
		//parsing(&line, input);
		ft_exe_master(&line);
		s_line_reset(&line);
	}
	(void)arg;
	(void)env;
	return (0);
}

int	main(int ac, char **arg, char **env)
{
	char	*input;
	char	*buff;
	t_line	line;


	ft_sig_init(ft_sig_handler_shell);
	term_init_setting(&line.old);
	s_line_init(&line);
	line.env = env;
	fill_lst_env(&line, 0);
	ft_var_env_update_shlvl(line.lst_env);
	while (1)
	{
		g_status = READING;
		input = readline("Enter something : ");
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
		{
			printf("exit\n");
			ft_clean_exit(&line, line.exit_status);
		}
		//parsing(&cmdline, line);
		line.cmd = ft_calloc(1, sizeof(t_cmd));
		if (!line.cmd)
			return (ft_perror_return_int(NULL));
		s_cmd_init(line.cmd);
		line.cmd->arg = ft_split(input, ' ');
		if (!line.cmd->arg[0])
			line.n_cmds = 0;
		else
			line.n_cmds = 1;
		if (!ft_strncmp(input, "code", 5))
			printf("g_status act is %d\n", g_status);
		else if (!ft_strncmp(input, "here", 5) || !ft_strncmp(input, "\"here\"", 7))
		{
			printf("delimiter : %s\n", input);
			buff = ft_here_doc_mode(input);
			printf("here_doc :\n%s\n", buff);
			free(buff);
		}
		else//if (line.cmd->arg && line.cmd->arg[0])
			ft_exe_master(&line);
		s_line_reset(&line);
		//if (g_status == SIGINT)
		//	g_status = 0;
	}
	(void) arg;
	(void) ac;
	return (0);
}

