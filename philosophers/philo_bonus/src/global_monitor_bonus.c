/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_monitor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:15:07 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 07:39:54 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	kill_em_philos(pid_t *pids, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		kill(pids[index], SIGKILL);
		index++;
	}
}

bool	gb_monitor(t_data *data)
{
	int	index;
	int	exit_code;

	index = 0;
	while (1)
	{
		index = 0;
		while (index < data->philo_count)
		{
			if (waitpid(data->pids[index++], &exit_code, WNOHANG) > 0
				&& WEXITSTATUS(exit_code) == EXIT_FAILURE)
			{
				kill_em_philos(data->pids, data->philo_count);
				return (true);
			}
		}
		ft_usleep(10);
	}
}
