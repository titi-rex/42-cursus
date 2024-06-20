/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:16:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/27 17:28:05 by tlegrand         ###   ########.fr       */
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

void	sem_killer(sem_t *sem, char *name)
{
	if (sem == SEM_FAILED)
		return ;
	if (sem)
		sem_close(sem);
	if (name)
		sem_unlink(name);
}

int	clear_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		sem_killer(data->philo[i].sem_time_meal, "/time");
	if (data->philo)
		free(data->philo);
	sem_killer(data->sem_print, "/print");
	sem_killer(data->sem_forks, "/forks");
	sem_killer(data->sem_meal, "/meal");
	sem_killer(data->sem_stop, "/stop");
	return (1);
}

void	p_print(t_philo *philo, char *str)
{
	sem_wait(philo->data->sem_print);
	printf("%ld %d %s\n", get_time() - philo->data->time_start, philo->id, str);
	sem_post(philo->data->sem_print);
}
