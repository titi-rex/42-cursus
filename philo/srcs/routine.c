/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:10:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/24 15:08:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	p_pause(t_philo *philo, long int duration)
{
	long int	end_time;
	long int	pause;

	end_time = get_time() + duration;
	pause = 10 * philo->data->n_philo;
	if (end_time == -1)
		return (-1);
	while (get_time() < end_time)
	{
		if (end(philo->data) || p_died(philo))
			return (1);
		usleep(pause);
	}
	return (0);
}

int	p_died(t_philo *philo)
{
	if (get_time() - philo->time_last_meal >= philo->data->time_death)
	{
		pthread_mutex_lock(&philo->data->m_death_note);
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(&philo->data->m_death_note);
			return (1);
		}
		philo->data->dead = -2;
		pthread_mutex_unlock(&philo->data->m_death_note);
		p_print(philo, "died");
		return (2);
	}
	return (0);
}

int	p_take_fork(t_philo *philo)
{
	int			wit;
	long int	pause;

	wit = 2;
	pause = 10 * philo->data->n_philo;
	while (wit)
	{
		pthread_mutex_lock(&philo->m_fork_left);
		if (philo->fork_left == 0)
		{
			philo->fork_left = philo->id;
			--wit;
			p_print(philo, "has taken a fork");
		}
		pthread_mutex_unlock(&philo->m_fork_left);
		if (philo->m_fork_right)
		{
			pthread_mutex_lock(philo->m_fork_right);
			if (*philo->fork_right == 0)
			{
				*philo->fork_right = philo->id;
				--wit;
				p_print(philo, "has taken a fork");
			}
			pthread_mutex_unlock(philo->m_fork_right);
		}
		if (p_died(philo) || end(philo->data))
			return (1);
		usleep(pause);
	}
	return (0);
}

int	p_give_back_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork_left);
	pthread_mutex_lock(philo->m_fork_right);
	philo->fork_left = 0;
	*philo->fork_right = 0;
	pthread_mutex_unlock(philo->m_fork_right);
	pthread_mutex_unlock(&philo->m_fork_left);
	return (0);
}

int	p_eat(t_philo *philo)
{
	if (p_take_fork(philo))
		return (1);
	philo->time_last_meal = get_time();
	p_print(philo, "is eating");
	++philo->n_meal;
	if (p_pause(philo, philo->data->time_eat))
		return (1);
	p_give_back_fork(philo);
	if (philo->n_meal == philo->data->n_meal)
	{
		pthread_mutex_lock(&philo->data->m_death_note);
		++philo->data->dead;
		pthread_mutex_unlock(&philo->data->m_death_note);
		return (1);
	}
	if (end(philo->data))
		return (1);
	return (0);
}
