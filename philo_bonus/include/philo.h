/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 16:55:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h> 
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				id;
	int				pid;
	long int		time_last_meal;
	int				n_meal;
	sem_t			*sem_time_meal;
	struct s_data	*data;

}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				n_philo;
	long int		time_death;
	long int		time_eat;
	long int		time_sleep;
	long int		time_start;
	long int		time_pause;
	int				n_meal;
	sem_t			*sem_forks;
	sem_t			*sem_stop;
	sem_t			*sem_print;
	sem_t			*sem_meal;
}	t_data;

int			parser(int ac, char **arg, t_data *data);
int			philo_init(t_data *data);
int			philo_launch(t_data *data);
void		*watching(void *ptr);
void		philosophing(t_philo *philo);
long int	p_last_meal(t_philo *philo, sem_t *sem_time_meal);
long int	get_time(void);
int			is_end(t_data *data);
void		clear_all(t_data *data);
void		p_print(t_philo *philo, char *str);

int			p_pause(long int duration, long int time_pause);
int			p_eat(t_philo *philo);
int			p_died(t_philo *philo);

#endif
