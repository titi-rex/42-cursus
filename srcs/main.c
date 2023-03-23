/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 17:40:12 by tlegrand         ###   ########.fr       */
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
	printf("Hello, welcome in minishell !\n");
	printf("by loulou and titi\n");
}

void	ft_init_main(t_line *line, char **env)
{
	s_line_init(line);
	ft_sig_init(ft_sig_handler_shell);
	term_init_setting(&line->old);
	fill_lst_env2(&line->lst_env, env);
	line->env = ft_lstenv_to_tab(line->lst_env);
}

void	ft_check_interrupt(int *exit_status)
{
	if (g_status & INTERRUPT)
	{
		g_status ^= INTERRUPT;
		*exit_status = 130;
	}
}

/*	FIXME:	< > not lean in first pos*/
/*	TODO: mettre au propre + norme	*/
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
		err = ft_browse_line(input, 0, 0, &line);
		free(input);
		if (err != 0)
			printf("Error parsing \n");
		else if (!(g_status & INTERRUPT))
			ft_exe_master(&line);
		s_line_reset(&line);
	}
	(void)arg;
	return (0);
}
