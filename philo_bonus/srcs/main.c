/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 00:08:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **arg)
{
	t_data	data;
	int		i;

	if (parser(ac, arg, &data))
		return (1);
	if (data.n_philo == 0)
		return (0);
	if (philo_init(&data))
		return (clear_all(&data), 1);
	i = philo_launch(&data);
	if (i)
		data.n_philo = i;
	i = 0;
	while (i < data.n_philo)
	{
		waitpid(data.philo[i].pid, NULL, 0);
		dprintf(2, "wait %d ", i);
		++i;
	}
	printf("dead is %d\n", data.dead);
	clear_all(&data);
	return (0);
}
