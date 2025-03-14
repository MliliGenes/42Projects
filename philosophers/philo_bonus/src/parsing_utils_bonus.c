/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:03:29 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/13 23:54:32 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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
	long long	tmp[5];
	int			index;

	index = 0;
	while (index < 5)
		tmp[index++] = -1;
	index = 0;
	while (index < 5 && args[index])
	{
		tmp[index] = ft_atoi(args[index]);
		if (tmp[index] == 0 || tmp[index] > INT_MAX)
			return (EXIT_FAILURE);
		index++;
	}
	params->pids = malloc(sizeof(pid_t) * (int)tmp[0]);
	if (!params->pids)
		return (EXIT_FAILURE);
	params->philo_count = (int)tmp[0];
	params->time_to_die = (int)tmp[1];
	params->time_to_eat = (int)tmp[2];
	params->time_to_sleep = (int)tmp[3];
	params->must_eat_count = (int)tmp[4];
	return (EXIT_SUCCESS);
}

int	check_params(t_data *params)
{
	if (params->philo_count > 200)
		return (EXIT_FAILURE);
	if (params->time_to_die < 60 || params->time_to_eat < 60
		|| params->time_to_sleep < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
