/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:30:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 19:16:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*watching(void *ptr)
{
	t_philo		*philo;
	sem_t		*sem_time_meal;
	long int	time[3];

	philo = ptr;
	time[0] = philo->data->time_death;
	time[1] = philo->data->time_pause;
	sem_time_meal = sem_open("/time", 0);
	usleep(time[0] * 0.9);
	while (1)
	{
		time[2] = p_last_meal(philo, sem_time_meal);
		if (time[2] < 0)
			exit(0);
		else if (get_time() - time[2] >= time[0])
		{
			sem_wait(philo->data->sem_print);
			printf("%ld %d %s\n", get_time() - philo->data->time_start, \
				philo->id, "died");
			sem_post(philo->data->sem_stop);
			exit(0);
		}
		usleep(time[1] * 10);
	}
	return (NULL);
}

long int	p_last_meal(t_philo *philo, sem_t *sem_time_meal)
{
	long int	time;

	time = -1;
	sem_wait(sem_time_meal);
	time = philo->time_last_meal;
	sem_post(sem_time_meal);
	return (time);
}
