/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:41:39 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/23 00:31:39 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_error_arg(int err)
{
	if (err == 1)
		printf("Error : need at least 4 arg\n");
	else if (err == 2)
		printf("Error : too much arg\n");
	else if (err == 3)
		printf("Error : negative value are not possible...\n");
	return (1);
}

static int	check_arg(t_data *data)
{
	if (data->n_philo < 0)
		return (1);
	if (data->time_death < 0)
		return (1);
	if (data->time_eat < 0)
		return (1);
	if (data->time_sleep < 0)
		return (1);
	return (0);
}

int	parser(int ac, char **arg, t_data *data)
{
	if (ac < 5)
		return (ft_error_arg(1));
	if (ac > 6)
		return (ft_error_arg(2));
	data->n_philo = ft_atoi(arg[1]);
	data->time_death = ft_atoi(arg[2]);
	data->time_eat = ft_atoi(arg[3]);
	data->time_sleep = ft_atoi(arg[4]);
	if (check_arg(data))
		return (ft_error_arg(3));
	if (ac == 6)
	{
		data->n_meal = ft_atoi(arg[5]);
		if (data->n_meal < 0)
			return (ft_error_arg(3));
	}
	else
		data->n_meal = -2;
	data->dead = 0;
	pthread_mutex_init(&data->m_write, NULL);
	pthread_mutex_init(&data->m_death, NULL);
	return (0);
}
