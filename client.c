/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 19:16:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	killstate;
	
	ft_printf("name is %s\n", argv[0]);

	if (argc == 2)
	{
		killstate = kill(ft_atoi(argv[1]), SIGUSR1);
		ft_printf("killstate is %d\n", killstate);
	}

	return(argc);
}