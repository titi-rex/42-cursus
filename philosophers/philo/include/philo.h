/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/04 21:02:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
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
	int				fork_left;
	int				*fork_right;
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
	pthread_mutex_t	m_death_note;
	pthread_mutex_t	m_start;
	int				dead;
}	t_data;

int			parser(int ac, char **arg, t_data *data);
int			parser_error(int err);
int			philo_init(t_data *data);
int			philo_launch(t_data *data);

long int	get_time(void);
int			is_end(t_data *data);
void		p_print(t_philo *philo, char *str);

int			p_pause(t_philo *philo, long int duration);
int			p_eat(t_philo *philo);
int			p_died(t_philo *philo);

#endif
