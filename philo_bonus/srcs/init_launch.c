/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:46:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/27 17:28:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_init(t_data *data)
{
	int	i;

	data->philo = malloc(data->n_philo * sizeof(t_philo));
	if (!data->philo)
		return (printf("Error : malloc failed\n"));
	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].pid = -1;
		data->philo[i].time_last_meal = 0;
		data->philo[i].n_meal = 0;
		data->philo->sem_time_meal = NULL;
		data->philo[i].data = data;
		++i;
	}
	return (0);
}

int	philo_create(t_philo *philo)
{
	philo->pid = fork();
	if (philo->pid == -1)
		return (-1);
	else if (philo->pid == 0)
		philosophing(philo);
	return (0);
}

int	philo_launch(t_data *data)
{
	int	i;

	i = 0;
	data->time_start = get_time();
	if (data->time_start == -1)
		return (-1);
	while (i < data->n_philo)
	{
		if (philo_create(&data->philo[i]))
			return (printf("Error : philo %d creation failed\n", i), i);
		++i;
	}
	while (i-- > 0)
		sem_post(data->sem_start);
	while (++i < data->n_philo)
		sem_wait(data->sem_stop);
	return (0);
}
