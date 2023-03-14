/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/14 13:18:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	ft_sig_handler_shell(int sig)
{
	if (g_status == MINISHELL)
	{
		dprintf(2, "SIGINT received while minishell inception");
		return ;
	}
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
		exit(sig);
}

void	ft_sig_init(void (*handler) (int sig))
{
	struct sigaction	act_int;
	struct sigaction	act_quit;

	act_int.sa_flags = 0;
	act_quit.sa_flags = 0;
	sigemptyset(&act_int.sa_mask);
	sigaddset(&act_int.sa_mask, SIGINT);
	act_int.sa_handler = handler;
	sigemptyset(&act_quit.sa_mask);
	sigaddset(&act_quit.sa_mask, SIGQUIT);
	act_quit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &act_int, NULL);
	sigaction(SIGQUIT, &act_quit, NULL);
}
