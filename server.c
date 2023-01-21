/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:09:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 23:53:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t	g_bin;

int	main(void)
{
	int				pid;
	int				bin;
	char			c;
	struct sigaction act;
	
	act.sa_handler = ft_handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaddset(&act.sa_mask, SIGTERM);
	sigaddset(&act.sa_mask, SIGFPE);
	pid = getpid();
	ft_printf("server pid is %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGFPE, &act, NULL);
	while (1)
	{
		if (g_bin > 9999999)
		{
			//sigemptyset(&act.sa_mask);
			bin = g_bin;
			g_bin = 0;
			c = ft_decoding(bin);
			if (bin != 11111111)
				write(1, &c, 1);
			else
				write(1, "\n", 1);
		}
	}	
	
	return (0);
}

/*
		if (ft_intlen(g_bin) == 8)
		{
			sigemptyset(&act.sa_mask);
			bin = g_bin;
			ft_decoding(bin);

		}
*/

/*
			sigaddset(&act.sa_mask, SIGUSR1);
			sigaddset(&act.sa_mask, SIGUSR2);
			sigaddset(&act.sa_mask, SIGTERM);
			sigaddset(&act.sa_mask, SIGFPE);
*/