/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:10:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 17:26:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	p_pause(t_philo *philo, long int duration)
{
	long int	start_time;

	start_time = get_time();
	if (start_time == -1)
		return (-1);
	while (get_time() - start_time < duration)
	{
		if (end(philo->data) || p_died(philo))
			return (1);
	}
	return (0);
}

int	p_died(t_philo *philo)
{
	if (get_time() - philo->time_last_meal >= philo->data->time_death)
	{
		pthread_mutex_lock(&philo->data->m_death);
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(&philo->data->m_death);
			return (1);
		}
		philo->data->dead = -1;
		pthread_mutex_unlock(&philo->data->m_death);
		p_print(philo, "died");
		return (2);
	}
	return (0);
}

int	p_take_fork(t_philo *philo, int *fork_l, int *fork_r)
{
	if (*fork_l == 0 && \
		pthread_mutex_lock(&philo->m_fork_left) == 0)
	{
		*fork_l = 1;
		p_print(philo, "has taken a fork");
	}
	if (*fork_r == 0 && philo->m_fork_right && \
		pthread_mutex_lock(philo->m_fork_right) == 0)
	{
		*fork_r = 1;
		p_print(philo, "has taken a fork");
	}
	if (p_died(philo))
	{
		dprintf(2, "%d dead taking fork\n", philo->id);
		if (*fork_l == 1)
			pthread_mutex_unlock(&philo->m_fork_left);
		if (*fork_r == 1)
			pthread_mutex_unlock(philo->m_fork_right);
		return (1);
	}
	return (0);
}

int	p_eat(t_philo *philo)
{
	int	wit_left;
	int	wit_right;

	wit_left = 0;
	wit_right = 0;
	while ((wit_left == 0 || wit_right == 0) && end(philo->data) == 0)
	{
		if (p_take_fork(philo, &wit_left, &wit_right))
			return (1);
	}
	p_print(philo, "is eating");
	++philo->n_meal;
	if (p_pause(philo, philo->data->time_eat))
		return (1);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->m_fork_left);
	pthread_mutex_unlock(philo->m_fork_right);
	if (philo->data->dead < 0)
		return (1);
	if (philo->n_meal == philo->data->n_meal)
	{
		pthread_mutex_lock(&philo->data->m_death);
		++philo->data->dead;
		pthread_mutex_unlock(&philo->data->m_death);
		return (1);
	}
	return (0);

}


