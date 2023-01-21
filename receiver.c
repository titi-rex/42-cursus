/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:16:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 00:02:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern sig_atomic_t g_bin;

void	ft_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		//ft_printf("1");
		g_bin = g_bin * 10 + 1;
	}
	if (sig == SIGUSR2)
	{
		//ft_printf("2");
		g_bin = g_bin * 10 + 2;
	}
	if (sig == SIGFPE)
	{
		g_bin = 0;
		write(1, "\n", 1);
	}
	if (sig == SIGTERM)
	{
		ft_printf("\ng_bin is %d\n", g_bin);
	}

}
