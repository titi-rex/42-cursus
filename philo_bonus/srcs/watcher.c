/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:30:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 00:05:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	watcher_init(t_watcher *watcher, t_philo *philo)
{
	watcher->pid = 0;
	watcher->philo = philo;
	watcher->sem_death_note = philo->data->sem_death_note;
	watcher->time_death = philo->data->time_death;
}

void	serial_killer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		kill(data->philo[i].pid, SIGQUIT);
}

void	*watching(void *ptr)
{
	t_philo		*philo;
	sem_t		*death;
	long int	time[2];

	philo = ptr;
	time[0] = philo->data->time_death;
	time[1] = philo->data->time_pause;
	death = sem_open("/death_note", O_RDWR);
	usleep(time[0] * 0.9);
	while (1)
	{
		if (get_time() - philo->time_last_meal >= time[0])
		{
			sem_wait(death);
			printf("%ld %d %s\n", get_time() - philo->data->time_start, \
				philo->id, "died");
			serial_killer(philo->data);
			exit(0);
		}
		usleep(time[1]);
	}
	return (NULL);
}
