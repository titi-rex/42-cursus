/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 00:00:59 by tlegrand         ###   ########.fr       */
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
	sem_close(data->sem_death_note);
	sem_unlink("/death_note");
	sem_close(data->sem_forks);
	sem_unlink("/forks");
}

void	p_print(t_philo *philo, char *str)
{
	sem_wait(philo->data->sem_death_note);
	if (philo->data->dead >= 0 || philo->data->dead == -philo->id)
		printf("%ld %d %s\n", get_time() - philo->data->time_start, \
			philo->id, str);
	sem_post(philo->data->sem_death_note);
}

int	is_end(t_data *data)
{
	sem_wait(data->sem_death_note);
	if (data->dead < 0 || data->dead == data->n_philo)
	{
		sem_post(data->sem_death_note);
		return (1);
	}
	sem_post(data->sem_death_note);
	return (0);
}
