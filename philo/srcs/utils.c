/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 17:28:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	end(t_data *data)
{
	pthread_mutex_lock(&data->m_death);
	if (data->dead < 0 || data->dead == data->n_philo)
	{
		pthread_mutex_unlock(&data->m_death);
		return (1);
	}
	pthread_mutex_unlock(&data->m_death);
	return (0);
}

long int	get_time(void)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	p_print(t_philo *philo, char *str)
{
	while (pthread_mutex_lock(&philo->data->m_write))
	{
		dprintf(2, "%d wait for writing\n", philo->id);
		continue ;
	}
	printf("%ld %d %s\n", get_time() - philo->data->time_start, philo->id, str);
	pthread_mutex_unlock(&philo->data->m_write);
	return (0);
}
