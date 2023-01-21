/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 00:04:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendout(int pid, int bin)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < 8)
	{
		if (bin % 10 == 1)
			n += kill(pid, SIGUSR1);
		else
			n += kill(pid, SIGUSR2);
		usleep(1);
		bin /= 10;
		i++;
	}
}

void	ft_sender_master(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		//ft_printf("char to send is %c\n", str[i]);
		ft_sendout(pid, ft_dectobin(str[i]));
		i++;
		usleep(10);
	}
	ft_sendout(pid, 11111111);
	usleep(5);
}

/*
	if (n != 0)
		ft_printf("Some signals are lost : %d\n", n);
	else
		ft_printf("All signals succesfully sent!\n");
*/