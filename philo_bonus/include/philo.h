/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:50:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/26 00:00:09 by tlegrand         ###   ########.fr       */
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
	sem_t			*sem_forks;
	struct s_data	*data;

}	t_philo;

typedef struct s_watcher
{
	pthread_t			pid;
	long int	time_death;
	t_philo		*philo;
	sem_t		*sem_death_note;
}	t_watcher;

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
	int				forks;
	sem_t			*sem_death_note;
	int				dead;
}	t_data;

int			parser(int ac, char **arg, t_data *data);
int			philo_init(t_data *data);
int			philo_launch(t_data *data);
void		watcher_init(t_watcher *watcher, t_philo *philo);
void		*watching(void *ptr);
void		philosophing(t_philo *philo);

long int	get_time(void);
int			is_end(t_data *data);
void		clear_all(t_data *data);
void		p_print(t_philo *philo, char *str);

int			p_pause(long int duration, long int time_pause);
int			p_eat(t_philo *philo);
int			p_died(t_philo *philo);

#endif
