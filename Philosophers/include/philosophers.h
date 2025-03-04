/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/03 21:47:14 by sel-mlil         ###   ########.fr       */
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
	int				time_to_die;
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

#endif

// haguezoum@gmail.com
// haguezoum