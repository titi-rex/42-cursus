/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 17:45:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_sendout(int pid, unsigned char bytes)
{
	uint8_t	count;
	int		n;

	n = 0;
	count = 1 << 7;
	while (count)
	{
		if (bytes & count)
			n += kill(pid, SIGUSR1);
		else
			n += kill(pid, SIGUSR2);
		usleep(200);
		count >>= 1;
	}
	return (n);
}

void	ft_sender_master(int pid, char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n = ft_sendout(pid, *str);
		str++;
	}
	n += ft_sendout(pid, 0);
	if (n)
		ft_error("Some signals were lost\n");
}

void	ft_sighandler_client(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("server confirm receipt of message\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	act.sa_handler = ft_sighandler_client;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR2, &act, NULL);
	if (argc == 3)
		ft_sender_master(ft_atoi(argv[1]), argv[2]);
	while (sleep(3))
		pause();
	ft_error("Server didn't confirm receipt\n");
	sleep(1);
	return (0);
}
