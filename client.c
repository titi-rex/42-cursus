/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 16:26:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_receipt;

int	main(int argc, char **argv)
{
	struct sigaction act;

	act.sa_handler = ft_sighandler_client;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR2, &act, NULL);
	if (argc == 2)
	{
		if (kill(ft_atoi(argv[1]), SIGTERM) == -1)
			ft_error("Fail to require server's shutdown\n");
	}
	else if (argc == 3)
		ft_sender_master(ft_atoi(argv[1]), argv[2]);
	else
	{
		if (kill(ft_atoi(argv[1]), SIGFPE) == -1)
			ft_error("Fail to ask statue of g_bin to server\n");
	}
	while(1)
		pause();
	return(0);
}
