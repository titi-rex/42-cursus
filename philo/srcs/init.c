/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:46:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/24 15:34:44 by tlegrand         ###   ########.fr       */
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
		data->philo[i].fork_left = 0;
		if (data->n_philo == 1)
			data->philo[i].m_fork_right = NULL;
		else
		{
			data->philo[i].m_fork_right = &data->philo[(i + 1) % data->n_philo].m_fork_left;
			data->philo[i].fork_right = &data->philo[(i + 1) % data->n_philo].fork_left;
		}
		data->philo[i].data = data;
		++i;
	}
	return (0);
}

void	*philosophing(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->time_last_meal = philo->data->time_start;
	p_print(philo, "is thinking");
	if (philo->id % 2 == 0)
		p_pause(philo, (philo->data->time_eat * 0.9));
	while (end(philo->data) == 0)
	{
		if (p_eat(philo))
			break ;
		p_print(philo, "is sleeping");
		if (p_pause(philo, philo->data->time_sleep))
			break ;
		p_print(philo, "is thinking");
	}
	philo->n_meal = -1;
	return (NULL);
}

int	philo_launch(t_data *data)
{
	int	i;
	int nb;

	i = 0;
	nb = data->n_philo;
	data->time_start = get_time();
	while (i < nb)
	{
		if (pthread_create(&data->philo[i].id_thread, NULL, &philosophing, \
			&data->philo[i]))
			return (i);
		++i;
	}
	return (0);
}
