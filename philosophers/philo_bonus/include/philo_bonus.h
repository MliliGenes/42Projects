/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/10 02:33:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum s_type
{
	ODD,
	EVEN
}				t_type;

typedef struct s_data
{
	int			philo_count;
	size_t		time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	long		start_time;
	int			must_eat_count;
}				t_data;

typedef struct s_philo
{
	int			id;
	t_type		type;
	pthread_t	thread;

	size_t		last_meal_time;
	int			meals_eaten;

	t_data		*data;
}				t_philo;

long long		ft_atoi(const char *nptr);
void			write_message(t_philo *philo, const char *message);
int				check_args(char **args);
int				fill_params(char **args, t_data *params);
int				check_params(t_data *params);
size_t			get_current_time(void);
void			ft_usleep(int duration, t_data *data);

// bool				getter(t_data *data);
// void				setter(t_data *data, bool flag);
// ;
// size_t				getter_last_meal(t_philo *philo);
// void				setter_last_meal(t_philo *philo);
// size_t				getter_time_to_die(t_data *data);
sem_t			*init_forks(int count);
// void				assign_forks(t_philo *philos, pthread_mutex_t *forks,
// 						int cœount);
// void				create_philo(t_philo *philo, t_data *data, int index);
// t_philo				*init_philos(t_data *data);
// void				action(t_philo *philo, int type);
// void				*routine(void *args);
// void				monitoring(t_philo *philos, t_data *data);
// void				start_simulation(t_data *data, t_philo *philos, int count);

#endif
