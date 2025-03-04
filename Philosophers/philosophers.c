/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:42 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/04 01:47:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool			getter(t_data *data);

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
	params->end_flag = false;
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
	while (get_current_time() < target)
	{
		if (getter(data))
			break ;
		usleep(200);
	}
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
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->data = data;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->last_meal_time = get_current_time();
	pthread_mutex_init(&philo->meal_mutex, NULL);
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

bool	getter(t_data *data)
{
	bool	flag;

	pthread_mutex_lock(&data->locker_mutex);
	flag = data->end_flag;
	pthread_mutex_unlock(&data->locker_mutex);
	return (flag);
}

long	getter_last_meal(t_philo *philo)
{
	long	flag;

	pthread_mutex_lock(&philo->meal_mutex);
	flag = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (flag);
}

void	setter_last_meal(t_philo *philo, long timestamp)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = timestamp;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

size_t	getter_time_to_die(t_data *data)
{
	size_t	flag;

	pthread_mutex_lock(&data->death_mutex);
	flag = data->time_to_die;
	pthread_mutex_unlock(&data->death_mutex);
	return (flag);
}

int	getter_id(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&philo->data->locker_mutex);
	flag = philo->id + 1;
	pthread_mutex_unlock(&philo->data->locker_mutex);
	return (flag);
}

void	setter(t_data *data, bool flag)
{
	pthread_mutex_lock(&data->locker_mutex);
	data->end_flag = flag;
	pthread_mutex_unlock(&data->locker_mutex);
}

void	write_message(t_philo *philo, const char *message)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (!philo->data->end_flag)
		printf("%ld %d %s\n", get_current_time() - philo->data->start_time,
			philo->id + 1, message);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	action(t_philo *philo, int type)
{
	if (type == 1)
		write_message(philo, "is thinking");
	else if (type == 2)
	{
		write_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
	else if (type == 3)
	{
		pthread_mutex_lock(philo->left_fork);
		write_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		write_message(philo, "has taken a fork");
		
		write_message(philo, "is eating");
		ft_usleep(philo->data->time_to_eat, philo->data);
		setter_last_meal(philo, get_current_time());
		
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		
	}
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->type == ODD)
		action(philo, 2);
	while (!getter(data))
	{
		action(philo, 1);
		action(philo, 3);
		action(philo, 2);
	}
	return (NULL);
}

void			monitoring(t_philo *philos, t_data *data);

void	start_simulation(t_data *data, t_philo *philos, int count)
{
	int	index;

	data->start_time = get_current_time();
	index = 0;
	while (index < count)
	{
		pthread_create(&philos[index].thread, NULL, routine,
			(void *)&philos[index]);
		index++;
	}
	monitoring(philos, data);
	index = 0;
	while (index < count)
	{
		pthread_join(philos[index].thread, NULL);
		index++;
	}
}

void	monitoring(t_philo *philos, t_data *data)
{
	int	i;
	int	done_count;

	while (!getter(data))
	{
		i = 0;
		done_count = 0;
		while (i < data->philo_count)
		{
			if (get_current_time()
				- getter_last_meal(&philos[i]) > (unsigned long)getter_time_to_die(data))
			{
				setter(data, true);
				pthread_mutex_lock(&data->write_mutex);
				printf("%ld %d died\n", get_current_time() - data->start_time,
					philos[i].id + 1);
				pthread_mutex_unlock(&data->write_mutex);
				return ;
			}
			if (data->must_eat_count != -1)
			{
				pthread_mutex_lock(&philos[i].meal_mutex);
				if (philos[i].meals_eaten >= data->must_eat_count)
					done_count++;
				pthread_mutex_unlock(&philos[i].meal_mutex);
			}
			i++;
		}
		if (data->must_eat_count != -1 && done_count == data->philo_count)
		{
			setter(data, true);
			return ;
		}
		usleep(100);
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
	forks = init_forks(data.philo_count);
	if (!forks)
		return (EXIT_FAILURE);
	philos = init_philos(&data);
	if (!philos)
		return (EXIT_FAILURE);
	assign_forks(philos, forks, data.philo_count);
	// start simulation
	pthread_mutex_init(&data.write_mutex, NULL);
	pthread_mutex_init(&data.locker_mutex, NULL);
	pthread_mutex_init(&data.death_mutex, NULL);
	start_simulation(&data, philos, data.philo_count);
	return (0);
}
