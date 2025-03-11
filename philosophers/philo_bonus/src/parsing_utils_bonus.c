/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:03:29 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/11 00:57:06 by sel-mlil         ###   ########.fr       */
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
