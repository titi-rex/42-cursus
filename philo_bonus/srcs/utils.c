/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 16:51:57 by tlegrand         ###   ########.fr       */
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

void	clear_all(t_data *data)
{
	if (data->philo)
		free(data->philo);
	sem_close(data->sem_print);
	sem_unlink("/print");
	sem_close(data->sem_forks);
	sem_unlink("/forks");
	sem_close(data->sem_stop);
	sem_unlink("/stop");
	sem_close(data->sem_meal);
	sem_unlink("/meal");
	sem_unlink("/time");
}

void	p_print(t_philo *philo, char *str)
{
	sem_wait(philo->data->sem_print);
	printf("%ld %d %s\n", get_time() - philo->data->time_start, philo->id, str);
	sem_post(philo->data->sem_print);
}
