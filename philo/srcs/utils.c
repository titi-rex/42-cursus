/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 00:53:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	end(t_data *data)
{
	if (data->dead < 0 || data->dead == data->n_philo)
		return (1);
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
