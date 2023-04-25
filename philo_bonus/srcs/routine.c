/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:10:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 00:00:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	p_pause(long int duration, long int time_pause)
{
	long int	end_time;

	end_time = get_time() + duration;
	if (end_time == -1)
		return (-1);
	usleep(duration * 0.9);
	while (get_time() < end_time)
		usleep(time_pause);
	return (0);
}

int	p_eat(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	p_print(philo, "has taken a fork");
	sem_wait(philo->data->sem_forks);
	p_print(philo, "has taken a fork");
	philo->time_last_meal = get_time();
	p_print(philo, "is eating");
	++philo->n_meal;
	p_pause(philo->data->time_eat, philo->data->time_pause);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
	return (0);
}

void	philosophing(t_philo *philo)
{
	t_watcher	watcher;

	watcher_init(&watcher, philo);
	pthread_create(&watcher.pid, NULL, watching, &watcher);
	philo->time_last_meal = philo->data->time_start;
	p_print(philo, "is thinking");
	if (philo->id % 2 == 0)
		p_pause(philo->data->time_eat * 0.9, philo->data->time_pause);
	while (is_end(philo->data) == 0)
	{
		p_eat(philo);
		if (philo->n_meal == philo->data->n_meal)
			break ;
		p_print(philo, "is sleeping");
		p_pause(philo->data->time_sleep, philo->data->time_pause);
		p_print(philo, "is thinking");
	}
	clear_all(philo->data);
	exit(0);
}
