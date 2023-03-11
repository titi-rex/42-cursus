/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:11:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/11 16:55:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int g_sig;

void	ft_sig_handler_child(int sig, siginfo_t *sig_info, void *context)
{
	dprintf(2, "sig recu : %d\n", sig);
	if (sig == SIGINT)
		g_sig = SIGINT;
	if (sig == SIGQUIT)
		g_sig = SIGQUIT;
	(void) sig_info;
	(void) context;
}

void	ft_sig_launch(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_sigaction = ft_sig_handler_child;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

/*
struct sigaction	acts1;
	struct sigaction	acts2;
	struct sigaction	act_sigterm;

	ft_printf("Server pid is %d\n", getpid());
	act_sigterm.sa_handler = ft_handler_sigterm;
	act_sigterm.sa_flags = 0;
	sigemptyset(&act_sigterm.sa_mask);
	sigaction(SIGTERM, &act_sigterm, NULL);
	acts1.sa_sigaction = ft_sighandler_server;
	acts1.sa_flags = SA_SIGINFO;
	sigemptyset(&acts1.sa_mask);
	sigaction(SIGUSR1, &acts1, NULL);
	acts2.sa_sigaction = ft_sighandler_server;
	acts2.sa_flags = SA_SIGINFO;
	sigemptyset(&acts2.sa_mask);
	sigaction(SIGUSR2, &acts2, NULL);
	*/