/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 13:51:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	sig_handler_shell(int sig)
{
	if (g_status & EXECUTION)
		return ;
	if (sig == SIGINT)
	{
		if (g_status ^ EXECUTION)
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_status |= INTERRUPT;
	}
}

void	sig_handler_child(int sig)
{
	exit(sig);
}

void	sig_init(void (*handler) (int sig), void (*handler_quit) (int sig))
{
	struct sigaction	act;
	struct sigaction	act_quit;

	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);
	act_quit.sa_flags = SA_RESTART;
	sigemptyset(&act_quit.sa_mask);
	sigaddset(&act_quit.sa_mask, SIGQUIT);
	act_quit.sa_handler = handler_quit;
	sigaction(SIGQUIT, &act_quit, NULL);
}
