/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/12 00:18:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;


/*	TODO: sigQUIT DOES NOTHING	actually it move cursor ??*/
void	ft_sig_handler_shell(int sig, siginfo_t *info, void *ctxt)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_on_new_line();
		g_status = SIGINT;
	}
	(void) info;
	(void) ctxt;
}

void	ft_sig_handler_child(int sig, siginfo_t *info, void *ctxt)
{
	exit(sig);
	(void) info;
	(void) ctxt;
}

void	ft_sig_init(void (*handler) (int sig, siginfo_t *info, void *ctxt))
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
