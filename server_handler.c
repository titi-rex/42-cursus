/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:16:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 16:10:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern sig_atomic_t g_bin;

void	ft_sighandler_server(int sig, siginfo_t *sig_info, void *contex)
{
	if (sig == SIGUSR1)
	{
		//ft_printf("1");
		g_bin = g_bin * 10 + 1;
	}
	else if (sig == SIGUSR2)
	{
		//ft_printf("0");
		g_bin = g_bin * 10 + 2;
	}
	if (g_bin == 11111111)
	{
		if (kill(sig_info->si_pid, SIGUSR2) == -1)
			ft_printf("Confirm receipt to %d failed\n", sig_info->si_pid);
		return ;
	}
	if (sig == SIGTERM)
	{
		ft_printf("Client %d required server to shutdown\n", sig_info->si_pid);
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGFPE)
	{
		ft_printf("g_bin is %d\n", g_bin);
		g_bin = 0;
		ft_printf("g_bin set to 0 now\n");
	}
	if (contex)
		ft_printf("");
}

