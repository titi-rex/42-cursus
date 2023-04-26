/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:41:39 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 17:05:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((int) sign * res);
}

static int	parser_error(int err)
{
	if (err == 1)
		printf("Error : need at least 4 arg\n");
	else if (err == 2)
		printf("Error : too much arg\n");
	else if (err == 3)
		printf("Error : negative value are not possible...\n");
	else if (err == 4)
		printf("Error : sem_open failed\n");
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

int	sem_create(t_data *data)
{
	sem_unlink("/print");
	sem_unlink("/forks");
	sem_unlink("/stop");
	sem_unlink("/time");
	sem_unlink("/meal");
	data->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->sem_print == SEM_FAILED)
		return (1);
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->n_philo);
	if (data->sem_forks == SEM_FAILED)
	{
		sem_close(data->sem_print);
		sem_unlink("/print");
		return (1);
	}
	data->sem_stop = sem_open("/stop", O_CREAT, 0644, 0);
	if (data->sem_forks == SEM_FAILED)
	{
		sem_close(data->sem_print);
		sem_unlink("/print");
		sem_close(data->sem_forks);
		sem_unlink("/forks");
		return (1);
	}
	data->sem_meal = sem_open("/meal", O_CREAT, 0644, 0);
	return (0);
}

int	parser(int ac, char **arg, t_data *data)
{
	if (ac < 5)
		return (parser_error(1));
	if (ac > 6)
		return (parser_error(2));
	data->n_philo = ft_atoi(arg[1]);
	data->time_death = ft_atoi(arg[2]);
	data->time_eat = ft_atoi(arg[3]);
	data->time_sleep = ft_atoi(arg[4]);
	data->time_pause = data->n_philo * 10;
	if (check_arg(data))
		return (parser_error(3));
	if (ac == 6)
	{
		data->n_meal = ft_atoi(arg[5]);
		if (data->n_meal < 0)
			return (parser_error(3));
	}
	else
		data->n_meal = -1;
	if (sem_create(data))
		return (parser_error(4));
	return (0);
}
