/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 23:58:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_receipt;

int	main(int argc, char **argv)
{
	int	killstate;

	if (argc == 2)
	{
		killstate = kill(ft_atoi(argv[1]), SIGTERM);
		ft_printf("killstate is %d\n", killstate);
	}
	else if (argc == 3)
	{
		ft_sender_master(ft_atoi(argv[1]), argv[2]);
	}
	else if (argc == 4)
	{
		killstate = kill(ft_atoi(argv[1]), SIGFPE);
		ft_printf("killstate is %d\n", killstate);
	}
	//ft_printf("receipt is %d\n", g_receipt);
	return(argc);
}
