/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:18:43 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 06:24:47 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/_types/_pid_t.h>
# include <sys/fcntl.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum s_type
{
	EVEN,
	ODD,
}			t_type;

typedef struct s_data
{
	pid_t	*pids;
	size_t	start_time;
	int		philo_count;
	size_t	time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	int		last_odd;
	sem_t	*forks;
	sem_t	*write;
	sem_t	*stop_start;
}			t_data;

typedef struct s_philo
{
	int		id;
	char	*name;
	t_type	type;
	size_t	last_meal_time;
	int		meals_eaten;
	sem_t	*locker;
	t_data	*data;
}			t_philo;

long long	ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
char		*ft_itoa(int n);
char		*ft_strjoin(char *s1, char *s2);
void		write_message(t_philo *philo, const char *message);
int			check_args(char **args);
int			fill_params(char **args, t_data *params);
int			check_params(t_data *params);
size_t		get_current_time(void);
void		ft_usleep(size_t duration);
void		init_sems(t_data *data);
t_philo		*init_philos(t_data *data);
void		do_routine(t_philo *philo);
bool		start_simulation(t_philo *philos, t_data *data);
bool		getter(t_philo *philo);
void		setter(t_philo *philo);
void		kill_em_philos(pid_t *pids, int count);
bool		gb_monitor(t_data *data);

#endif
