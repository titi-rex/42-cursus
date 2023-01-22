/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:09:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 17:52:30 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler_server(int sig, siginfo_t *sig_info, void *contex)
{
	static int				count;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c = c | 128 >> count;
	count++;
	if (count == 8)
	{
		count = 0;
		if (c == 0)
		{
			write(1, "\n", 1);
			if (kill(sig_info->si_pid, SIGUSR2) == -1)
				ft_printf("Confirm receipt to %d failed\n", sig_info->si_pid);
		}
		else
			write(1, &c, 1);
		c = 0;
	}
	if (contex)
		return ;
}

int	main(void)
{
	struct sigaction	acts1;
	struct sigaction	acts2;

	ft_printf("Server pid is %d\n", getpid());
	acts1.sa_sigaction = ft_sighandler_server;
	acts1.sa_flags = SA_SIGINFO;
	sigemptyset(&acts1.sa_mask);
	sigaction(SIGUSR1, &acts1, NULL);
	acts2.sa_sigaction = ft_sighandler_server;
	acts2.sa_flags = SA_SIGINFO;
	sigemptyset(&acts2.sa_mask);
	sigaction(SIGUSR2, &acts2, NULL);
	while (1)
		pause();
	return (0);
}
