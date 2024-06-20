/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:10:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/27 17:28:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	p_pause(long int duration, long int time_pause)
{
	long int	end_time;

	end_time = get_time() + duration;
	if (end_time == -1)
		return (-1);
	usleep(duration * 0.8);
	while (get_time() < end_time)
		usleep(time_pause * 5);
	return (0);
}

int	p_eat(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	p_print(philo, "has taken a fork");
	sem_wait(philo->data->sem_forks);
	p_print(philo, "has taken a fork");
	sem_wait(philo->sem_time_meal);
	philo->time_last_meal = get_time();
	p_print(philo, "is eating");
	++philo->n_meal;
	sem_post(philo->sem_time_meal);
	p_pause(philo->data->time_eat, philo->data->time_pause);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
	if (philo->n_meal == philo->data->n_meal)
		return (1);
	return (0);
}

void	philosophing(t_philo *philo)
{
	pthread_t	watcher_pid;

	philo->time_last_meal = philo->data->time_start;
	philo->sem_time_meal = sem_open("/time", O_CREAT, S_IRWXU, 1);
	sem_wait(philo->data->sem_start);
	sem_post(philo->data->sem_stop);
	pthread_create(&watcher_pid, NULL, watching, philo);
	p_print(philo, "is thinking");
	if (philo->id % 2 == 0)
		p_pause(philo->data->time_eat * 0.9, philo->data->time_pause);
	while (1)
	{
		if (p_eat(philo))
			sem_post(philo->data->sem_meal);
		p_print(philo, "is sleeping");
		p_pause(philo->data->time_sleep, philo->data->time_pause);
		p_print(philo, "is thinking");
	}
	pthread_join(watcher_pid, NULL);
	clear_all(philo->data);
	exit(0);
}
