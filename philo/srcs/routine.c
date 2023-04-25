/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:10:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/25 19:16:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	p_pause(t_philo *philo, long int duration)
{
	long int	end_time;

	end_time = get_time() + duration;
	if (end_time == -1)
		return (-1);
	while (get_time() < end_time)
	{
		if (is_end(philo->data) || p_died(philo))
			return (1);
		usleep(philo->data->time_pause);
	}
	return (0);
}

void	p_take_fork(pthread_mutex_t *m_fork, t_philo *p, int *fork, int *wit)

{
	pthread_mutex_lock(m_fork);
	if (*fork == 0)
	{
		*fork = p->id;
		--(*wit);
		p_print(p, "has taken a fork");
	}
	pthread_mutex_unlock(m_fork);
}

int	p_try_fork(t_philo *philo)
{
	pthread_mutex_t	*m_fork[2];
	int				wit;

	m_fork[0] = &philo->m_fork_left;
	m_fork[1] = philo->m_fork_right;
	wit = 2;
	while (wit)
	{
		p_take_fork(m_fork[0], philo, &philo->fork_left, &wit);
		if (m_fork[1])
			p_take_fork(m_fork[1], philo, philo->fork_right, &wit);
		if (p_died(philo) || is_end(philo->data))
			return (1);
		usleep(philo->data->time_pause);
	}
	return (0);
}

int	p_give_back_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork_left);
	philo->fork_left = 0;
	pthread_mutex_unlock(&philo->m_fork_left);
	pthread_mutex_lock(philo->m_fork_right);
	*philo->fork_right = 0;
	pthread_mutex_unlock(philo->m_fork_right);
	return (0);
}

int	p_eat(t_philo *philo)
{
	if (p_try_fork(philo))
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
	if (is_end(philo->data))
		return (1);
	return (0);
}
