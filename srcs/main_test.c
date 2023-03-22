/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/22 20:58:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

sig_atomic_t	g_status = 0;

int		ft_man(int num);
void	ft_greeting(void);



void	ft_init_main(t_line *line, char **env)
{
	s_line_init(line);
	ft_sig_init(ft_sig_handler_shell);
	term_init_setting(&line->old);
	fill_lst_env2(&line->lst_env, env);
	line->env = ft_lstenv_to_tab(line->lst_env);
}

/*	TODO:	secret env	*/

/*	FIXME:	prompt one line write on first line */
/*	FIXME:	fd open at exit	*/
/*	TODO: mettre au propre + norme	*/
int	fmain(int ac, char **arg, char **env)
{
	char	*input;
	char	*prompt;
	t_line	line;

	if (ac != 1)
		return (1);
	ft_init_main(&line, env);
	prompt = ft_get_a_nice_prompt(line.lst_env, line.exit_status);
	while (1)
	{
		g_status = READING;
		input = readline(prompt);
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
		{
			ft_putendl_fd("exit", 1);
			ft_clean_exit(&line, line.exit_status);
		}
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

int	main(int ac, char **arg, char **env)
{
	char	*input;
	char	*prompt;
	t_line	line;

	
	// if (!access(arg[1], F_OK))
	// 	printf("accces ok\n");
	// else
	// 	printf("accces nop\n");
	// exit(0);
	if (ac != 1)
		return (ft_man(0));
	else
		ft_greeting();
	ft_init_main(&line, env);
	prompt = NULL;
	while (1)
	{
		if (g_status & INTERRUPT)
		{
			g_status ^= INTERRUPT;
			line.exit_status = 130;
		}
		if (g_status ^ MINISHELL)
			g_status |= READING;
		prompt = ft_get_a_nice_prompt(line.lst_env, line.exit_status);
		if (prompt)
		{
			input = readline(prompt);
			free(prompt);
		}
		else
			input = readline("guest@minishell $> ");
		if (input && input[0] != '\0')
			add_history(input);
		else if (!input)
		{
			ft_putendl_fd("exit", 1);
			term_reset(&line.old);
			ft_clean_exit(&line, line.exit_status);
		}
		if (ft_browse_line(input, 0, 0, &line) != 0)
		{
			dprintf(2, "Error parsing \n");
			free(input);
			input = NULL;
		}
		else
		{
			free(input);
			input = NULL;
			ft_exe_master(&line);
		}
		s_line_reset(&line);
	}
	(void) arg;
	return (0);
}

int	ft_man(int num)
{
	if (num == 0)
	{
		printf("Minishell shall not take argument nor parameter\n");
		return (1);
	}
	return (0);
}

void	ft_greeting(void)
{
	printf("Hello, welcome in minishell !\n");
	printf("by loulou and titi\n");
}
