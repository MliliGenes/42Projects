/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:22:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/16 09:39:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	kill_em_philos(pid_t *pids, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		kill(pids[index], SIGTERM);
		index++;
	}
}

void	action(t_philo *philo, int type)
{
	if (type == 1)
		write_message(philo, "is thinking");
	else if (type == 2)
	{
		write_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
	else if (type == 3)
	{
		sem_wait(philo->data->forks);
		write_message(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		write_message(philo, "has taken a fork");
		write_message(philo, "is eating");
		setter(philo);
		ft_usleep(philo->data->time_to_eat);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (getter(philo))
		{
			write_message(philo, "died");
			exit(EXIT_FAILURE);
		}
		ft_usleep(50);
	}
	return (NULL);
}

void	do_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitor, philo))
		exit(EXIT_FAILURE);
	pthread_detach(monitor_thread);
	if (philo->type == ODD)
		action(philo, 2);
	while (true)
	{
		action(philo, 1);
		action(philo, 3);
		if (philo->data->must_eat_count != -1
			&& philo->meals_eaten == philo->data->must_eat_count)
			exit(EXIT_SUCCESS);
		action(philo, 2);
	}
	exit(EXIT_SUCCESS);
}

bool	start_simulation(t_philo *philos, t_data *data)
{
	int	index;
	int	exit_code;

	data->start_time = get_current_time();
	index = 0;
	while (index < data->philo_count)
	{
		data->pids[index] = fork();
		if (data->pids[index] == -1)
			return (false);
		if (data->pids[index] == 0)
			do_routine(&philos[index]);
		index++;
	}
	index = 0;
	while (index < data->philo_count)
	{
		if (waitpid(data->pids[index], &exit_code, 0) > 0
			&& WEXITSTATUS(exit_code) == EXIT_FAILURE)
			kill_em_philos(data->pids, data->philo_count);
		index++;
	}
	return (true);
}
