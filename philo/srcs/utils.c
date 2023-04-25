/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/25 19:16:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	get_time(void)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : gettime failed\n");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	p_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->m_death_note);
	if (philo->data->dead >= 0 || philo->data->dead == -philo->id)
		printf("%ld %d %s\n", get_time() - philo->data->time_start, \
			philo->id, str);
	pthread_mutex_unlock(&philo->data->m_death_note);
}

int	p_died(t_philo *philo)
{
	if (get_time() - philo->time_last_meal >= philo->data->time_death)
	{
		pthread_mutex_lock(&philo->data->m_death_note);
		if (philo->data->dead < 0)
		{
			pthread_mutex_unlock(&philo->data->m_death_note);
			return (1);
		}
		philo->data->dead = -philo->id;
		pthread_mutex_unlock(&philo->data->m_death_note);
		p_print(philo, "died");
		return (2);
	}
	return (0);
}

int	is_end(t_data *data)
{
	pthread_mutex_lock(&data->m_death_note);
	if (data->dead < 0 || data->dead == data->n_philo)
	{
		pthread_mutex_unlock(&data->m_death_note);
		return (1);
	}
	pthread_mutex_unlock(&data->m_death_note);
	return (0);
}
