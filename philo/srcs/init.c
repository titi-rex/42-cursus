/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:46:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 01:11:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_init(t_data *data)
{
	int	i;

	data->philo = malloc(data->n_philo * sizeof(t_philo));
	if (!data->philo)
		return (1);
	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_last_meal = 0;
		data->philo[i].n_meal = 0;
		pthread_mutex_init(&data->philo[i].m_fork_left, NULL);
		if (data->n_philo == 1)
			data->philo[i].m_fork_right = NULL;
		else if (i < data->n_philo - 1)
			data->philo[i].m_fork_right = &data->philo[i + 1].m_fork_left;
		else
			data->philo[i].m_fork_right = &data->philo[0].m_fork_left;
		data->philo[i].data = data;
		++i;
	}
	return (0);
}

void	*philosophing(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->time_last_meal = get_time();
	if (philo->id % 2 == 0)
		p_pause(philo, philo->data->time_eat);
	while (end(philo->data) == 0 && p_died(philo) == 0)
	{
		if (p_eat(philo))
			break ;
		p_print(philo, "is sleeping");
		if (p_pause(philo, philo->data->time_sleep))
			break ;
		p_print(philo, "is thinking");
	}
	return (NULL);
}

int	philo_launch(t_data *data)
{
	int	i;

	i = 0;
	data->time_start = get_time();
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].id_thread, NULL, &philosophing, \
			&data->philo[i]))
			return (i);
		pthread_detach(data->philo[i].id_thread);
		++i;
	}
	return (0);
}
