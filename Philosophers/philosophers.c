/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:42 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/01 00:11:41 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		if (!args[i][0])
			return (EXIT_FAILURE);
		j = 0;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	fill_params(char **args, t_data *params)
{
	int	tmp[5];
	int	index;

	index = 0;
	while (index < 5)
		tmp[index++] = -1;
	index = 0;
	while (index < 5 && args[index])
	{
		tmp[index] = ft_atoi(args[index]);
		if (tmp[index] == 0)
			return (EXIT_FAILURE);
		index++;
	}
	params->philo_count = tmp[0];
	params->time_to_die = tmp[1];
	params->time_to_eat = tmp[2];
	params->time_to_sleep = tmp[3];
	params->must_eat_count = tmp[4];
	params->philosophers_done = 0;
	params->end_flag = 0;
	return (EXIT_SUCCESS);
}

int	check_params(t_data *params)
{
	if (params->must_eat_count == 0)
		return (EXIT_FAILURE);
	if (params->philo_count < 1 || params->philo_count > 200)
		return (EXIT_FAILURE);
	if (params->time_to_die < 60 || params->time_to_eat < 60
		|| params->time_to_sleep < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int duration, t_data *data)
{
	size_t	target;

	target = get_current_time() + duration;
	while (target > get_current_time() && data && !data->end_flag)
		usleep(50);
}

pthread_mutex_t	*init_forks(int count)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * count);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	assign_forks(t_philo *philos, pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % count];
		i++;
	}
}

void	create_philo(t_philo *philo, t_data *data, int index)
{
	philo->id = index;
	philo->type = index % 2;
	philo->last_meal_time = data->start_time;
	philo->meals_eaten = 0;
	philo->data = data;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
}

t_philo	*init_philos(t_data *data)
{
	int		index;
	t_philo	*philos_arr;

	philos_arr = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos_arr)
		return (NULL);
	index = 0;
	while (index < data->philo_count)
	{
		create_philo(&philos_arr[index], data, index);
		index++;
	}
	return (philos_arr);
}

void	write_message(t_philo *philo, const char *message)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%ld %d %s\n", get_current_time() - philo->data->start_time,
		philo->id + 1, message);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	action(t_philo *philo, const char *message, int sleep_time,
		pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	if (fork1)
	{
		pthread_mutex_lock(fork1);
		write_message(philo, "has taken a fork");
	}
	if (fork2)
	{
		pthread_mutex_lock(fork2);
		write_message(philo, "has taken a fork");
	}
	write_message(philo, message);
	if (sleep_time > 0)
		ft_usleep(sleep_time, philo->data);
	if (fork2)
		pthread_mutex_unlock(fork2);
	if (fork1)
		pthread_mutex_unlock(fork1);
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->type == ODD)
		action(philo, "is thinking", data->time_to_eat, NULL, NULL);
	while (1)
	{
		action(philo, "is eating", data->time_to_eat, philo->right_fork,
			philo->left_fork);
		philo->last_meal_time = get_current_time();
		philo->meals_eaten++;
		action(philo, "is sleeping", data->time_to_sleep, NULL, NULL);
		action(philo, "is thinking", 0, NULL, NULL);
	}
	return (NULL);
}

void	start_simulation(t_philo *philos, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		pthread_create(&philos[index].thread, NULL, routine,
			(void *)&philos[index]);
		index++;
	}
	index = 0;
	while (index < count)
	{
		pthread_join(philos[index].thread, NULL);
		index++;
	}
}

int	main(int ac, char *av[])
{
	t_data			data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	// parsing
	if (ac > 6 || ac < 5)
		return (EXIT_FAILURE);
	if (check_args(av + 1))
		return (EXIT_FAILURE);
	if (fill_params(av + 1, &data))
		return (EXIT_FAILURE);
	if (check_params(&data))
		return (EXIT_FAILURE);
	
	// setting things up
	data.start_time = get_current_time();
	forks = init_forks(data.philo_count);
	if (!forks)
		return (EXIT_FAILURE);
	philos = init_philos(&data);
	if (!philos)
		return (EXIT_FAILURE);
	assign_forks(philos, forks, data.philo_count);
	
	// start simulation
	pthread_mutex_init(&data.write_mutex, NULL);
	pthread_mutex_init(&data.death_state_mutex, NULL);
	pthread_mutex_init(&data.ate_mutex, NULL);
	pthread_mutex_init(&data.end_mutex, NULL);
	start_simulation(philos, data.philo_count);
	
	// monitoring thread
}
