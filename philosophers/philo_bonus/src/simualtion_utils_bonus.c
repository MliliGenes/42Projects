/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:22:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 07:48:07 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	action(t_philo *philo, int type)
{
	if (type == 1)
		write_message(philo, "\033[0;90mis thinking\033[0m");
	else if (type == 2)
	{
		write_message(philo, "\033[0;34mis sleeping\033[0m");
		ft_usleep(philo->data->time_to_sleep);
	}
	else if (type == 3)
	{
		sem_wait(philo->data->forks);
		write_message(philo, "\033[0;33mhas taken a fork\033[0m");
		sem_wait(philo->data->forks);
		write_message(philo, "\033[0;33mhas taken a fork\033[0m");
		write_message(philo, "\033[0;32mis eating\033[0m");
		setter(philo);
		ft_usleep(philo->data->time_to_eat);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
	if (philo->data->must_eat_count != -1 && philo->id == philo->data->last_odd
		&& philo->meals_eaten == philo->data->must_eat_count)
		exit(EXIT_FAILURE);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!getter(philo))
		ft_usleep(10);
	sem_wait(philo->data->write);
	printf("%ld %d \033[1;31mdied\033[0m\n", get_current_time()
		- philo->data->start_time, philo->id + 1);
	exit(EXIT_FAILURE);
	return (NULL);
}

void	do_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	sem_wait(philo->data->stop_start);
	philo->last_meal_time = get_current_time();
	if (pthread_create(&monitor_thread, NULL, monitor, philo))
		exit(EXIT_FAILURE);
	if (philo->type == ODD)
		action(philo, 2);
	while (true)
	{
		action(philo, 1);
		action(philo, 3);
		action(philo, 2);
	}
	pthread_join(monitor_thread, NULL);
}

bool	start_simulation(t_philo *philos, t_data *data)
{
	int	index;

	index = 0;
	data->start_time = get_current_time();
	while (index < data->philo_count)
	{
		data->pids[index] = fork();
		if (data->pids[index] == -1)
			return (false);
		if (data->pids[index] == 0)
		{
			do_routine(&philos[index]);
			exit(EXIT_SUCCESS);
		}
		index++;
	}
	index = 0;
	while (index < data->philo_count)
	{
		sem_post(data->stop_start);
		index++;
	}
	return (gb_monitor(data));
}
