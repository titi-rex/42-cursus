/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 13:37:36 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

sig_atomic_t	g_status = 0;

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
	if (!isatty(1))
		return ;
	printf(CLEAR CURSOR"Hello, welcome in "BOLD YELLOW"minishell !\n"END);
	printf("by "BOLD RED BLINK_FAS"loulou"END" and "BOLD CYAN BLINK_FAS \
		"titi"END"\n");
}

void	ft_init_main(t_line *line, char **env)
{
	s_line_init(line);
	sig_init(sig_handler_shell);
	term_init_setting(&line->old);
	ft_env_init(&line->lst_env, env);
	line->env = ft_env_lst_to_tab(line->lst_env);
}

void	ft_check_interrupt(int *exit_status)
{
	if (g_status & INTERRUPT)
	{
		g_status ^= INTERRUPT;
		*exit_status = 130;
	}
}

int	main(int ac, char **arg, char **env)
{
	char	*input;
	t_line	line;
	int		err;

	if (ac != 1)
		return (ft_man(0));
	else
		ft_greeting();
	ft_init_main(&line, env);
	while (1)
	{
		ft_check_interrupt(&line.exit_status);
		input = ft_get_input(&line);
		err = ft_parse_line(input, -1, 0, &line);
		free(input);
		if (err != 0)
			ft_printf("Error parsing\n");
		else if (!(g_status & INTERRUPT))
			exe_master(&line);
		s_line_reset(&line);
	}
	(void)arg;
	return (0);
}
