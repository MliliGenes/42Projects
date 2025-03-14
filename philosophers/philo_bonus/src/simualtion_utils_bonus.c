/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:22:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/14 01:32:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <signal.h>

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
void	do_routine(t_philo *philo)
{
	if (philo->id == 2)
	{	
		printf("i am philo %d DYING\n", philo->id);
		ft_usleep(1000);
		exit(EXIT_FAILURE);
	}
	printf("i am philo %d\n", philo->id);
	exit(EXIT_SUCCESS);
}

bool	start_simulation(t_philo *philos, t_data *data)
{
	int	index;
	int	exit_code;

	index = 0;
	while (index < data->philo_count)
	{
		data->pids[index] = fork();
		if (data->pids[index] == -1)
			return (false); // cleaning
		if (data->pids[index] == 0)
			do_routine(&philos[index]);
		index++;
	}
	index = 0;
	while (index < data->philo_count)
	{
		waitpid(data->pids[index], &exit_code, 0);
		if (WEXITSTATUS(exit_code) == EXIT_FAILURE)
			kill_em_philos(data->pids, data->philo_count);
		index++;
	}
	return (true);
}
