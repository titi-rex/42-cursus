/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 15:52:09 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	clear_all(t_data *data)
{
	while (--data->n_philo > 0)
		pthread_mutex_destroy(&data->philo[data->n_philo].m_fork_left);
	free(data->philo);
	pthread_mutex_destroy(&data->m_death_note);
}

int	main(int ac, char **arg)
{
	t_data	data;
	int		i;

	if (parser(ac, arg, &data))
		return (1);
	if (data.n_philo == 0)
		return (0);
	if (philo_init(&data))
		return (1);
	i = philo_launch(&data);
	if (i)
		data.n_philo = i;
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.philo[i].id_thread, NULL);
		++i;
	}
	clear_all(&data);
	return (0);
}
