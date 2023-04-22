/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/22 23:59:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		id_thread;
	long int		time_last_meal;
	int				n_meal;
	pthread_mutex_t	m_fork_left;
	pthread_mutex_t	*m_fork_right;
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
	int				n_meal;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_death;
	int				dead;
}	t_data;

int			parser(int ac, char **arg, t_data *data);
int			philo_init(t_data *data);
int			philo_launch(t_data *data);
int			ft_atoi(char *str);

long int	get_time(void);
int			end(t_data *data);
int			p_print(t_philo *philo, char *str);


int			p_pause(t_philo *philo, long int duration);
int			p_eat(t_philo *philo);
int			p_died(t_philo *philo);

#endif

/*

memset
printf write
malloc / free
gettimeofdat
pthread : 
-create
-detach
-join
mutex :
-init
-destroy
-lock
-unlpck
*/