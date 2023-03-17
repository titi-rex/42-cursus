/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/16 17:23:28 by tlegrand         ###   ########.fr       */
=======
/*   Updated: 2023/03/17 15:30:34 by tlegrand         ###   ########.fr       */
>>>>>>> loulouleretour
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

sig_atomic_t	g_status = 0;

// /*
// PWD
// time
// user
// exit status 
// machine
// TIME_UTC
// */

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
		//if (parsing(&line, input))
		//{
		//		ft_putendl_fd("Error parsing\n", 2);
		//		continue ;
		//}
		ft_exe_master(&line);
		s_line_reset(&line);
	}
	(void)arg;
	(void)env;
	return (0);
}

int main(int ac, char **arg, char **env)
{
	char	*input;
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
		input = readline("\033[1;35mEnter something : \033[0m");
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
		{
			printf("exit\n");
			ft_clean_exit(&line, line.exit_status);
<<<<<<< HEAD
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
=======
		ft_browse_line(input, 0, 0, &line);
		free(input);
		input = NULL;
		//printf("line = %s\n", line.cmd->next->arg[1]);
		//if (!ft_strncmp(input, "code", 5))
		//	printf("g_status act is %d\n", g_status);
		ft_exe_master(&line);
		//dprintf(2, "inout : %s\n", input);
>>>>>>> loulouleretour
		s_line_reset(&line);
	}
	(void) arg;
	(void) ac;
	return (0);
}

