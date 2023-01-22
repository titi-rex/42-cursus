/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 16:27:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_sendout(int pid, unsigned char bytes)
{
	uint8_t	count;
	int		n;

	n = 0;
	count = 1;
	count = count << 7;
	while (count)
	{
		if (bytes & count)
			n += kill(pid, SIGUSR1);
		else
			n += kill(pid, SIGUSR2);
		usleep(100);
		count = count >> 1;
	}
	return (n);
}

void	ft_sender_master(int pid, char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = ft_sendout(pid, str[i]);
		i++;
		usleep(100);
	}
	n += ft_sendout(pid, 255);
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

