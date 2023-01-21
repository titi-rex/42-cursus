/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:09:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 18:58:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	count = 0;

void	ft_handle_sig1(int sig)
{
	count++;
	ft_printf("got it ! %d \n", count);
	(void) sig;
}

int	main(void)
{
	int	pid;
	struct sigaction act;
	
	act.sa_handler = ft_handle_sig1;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	pid = getpid();
	ft_printf("server pid is %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	while (count < 3)
		ft_printf("");
	
	return (0);
}
