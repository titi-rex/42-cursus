/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/16 17:40:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	ft_sig_handler_shell(int sig)
{
	if (sig == SIGINT)
	{
		if (g_status != EXECUTION)
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_status = SIGINT;
	}
}

void	ft_sig_handler_child(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr_fd("Quit\n", 2);
	exit(sig);
}

void	ft_sig_init(void (*handler) (int sig))
{
	struct sigaction	act;

	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
