/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_data(t_data *data)
{
	printf("n_philo	: %d\n", data->n_philo);
	printf("time_death	: %ld\n", data->time_death);
	printf("time_eat	: %ld\n", data->time_eat);
	printf("time_sleep	: %ld\n", data->time_sleep);
	printf("n_meal	: %d\n", data->n_meal);
	printf("dead	: %d\n", data->dead);
}

int	ending(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].id_thread, NULL);
		printf("wait%d ", i);
		++i;
	}
	return (0);
}

int	main(int ac, char **arg)
{
	t_data	data;

	if (parser(ac, arg, &data))
		return (1);
	if (data.n_philo == 0)
		return (0);
	print_data(&data);
	if (philo_init(&data))
		return (1);
	if (philo_launch(&data))
		return (1);
	while (end(&data) == 0)
		continue ;
	ending(&data);
	if (data.n_meal != -2 && data.dead == data.n_philo)
		printf("All philosophers had ate enough\n");
	return (0);
}
