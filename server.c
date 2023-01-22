/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:09:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 16:10:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t	g_bin;

int	main(void)
{
	unsigned char		c;
	int					bin;
	struct sigaction	act;
	
	ft_printf("Server pid is %d\n", getpid());
	act.sa_sigaction = ft_sighandler_server;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGFPE, &act, NULL);
	while (1)
	{
		if (g_bin > 9999999)
		{
			
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
