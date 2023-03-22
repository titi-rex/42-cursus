/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/22 11:20:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	ft_sig_handler_shell(int sig)
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

void	ft_sig_handler_child(int sig)
{
	exit(sig);
}

void	ft_sig_init(void (*handler) (int sig))
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
	act_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act_quit, NULL);
}
