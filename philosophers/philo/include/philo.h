/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/10 02:33:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum s_type
{
	ODD,
	EVEN
}					t_type;

typedef struct s_data
{
	int				philo_count;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	long			start_time;

	int				must_eat_count;
	int				philosophers_done;
	int				end_flag;

	pthread_mutex_t	write_mutex;
	pthread_mutex_t	locker_mutex;
	pthread_mutex_t	death_mutex;

}					t_data;

typedef struct s_philo
{
	int				id;
	t_type			type;
	pthread_t		thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;

	size_t			last_meal_time;
	int				meals_eaten;

	t_data			*data;
}					t_philo;

int					ft_atoi(const char *nptr);
void				write_message(t_philo *philo, const char *message);
int					check_args(char **args);
int					fill_params(char **args, t_data *params);
int					check_params(t_data *params);
size_t				get_current_time(void);
void				ft_usleep(int duration, t_data *data);
bool				getter(t_data *data);
void				setter(t_data *data, bool flag);
;
size_t				getter_last_meal(t_philo *philo);
void				setter_last_meal(t_philo *philo);
size_t				getter_time_to_die(t_data *data);
pthread_mutex_t		*init_forks(int count);
void				assign_forks(t_philo *philos, pthread_mutex_t *forks,
						int cœount);
void				create_philo(t_philo *philo, t_data *data, int index);
t_philo				*init_philos(t_data *data);
void				action(t_philo *philo, int type);
void				*routine(void *args);
void				monitoring(t_philo *philos, t_data *data);
void				start_simulation(t_data *data, t_philo *philos, int count);

#endif
