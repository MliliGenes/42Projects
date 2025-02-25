/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:00:42 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/25 16:27:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"
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

int	check_args(char *args[])
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

int	fill_params(char *args[], t_params *params)
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
	params->philos_count = tmp[0];
	params->time_to_die = tmp[1];
	params->time_to_eat = tmp[2];
	params->time_to_sleep = tmp[3];
	if (tmp[4] != -1)
		params->meals_count = tmp[4];
	params->meals_count = tmp[4];
	return (EXIT_SUCCESS);
}
void	set(char **av)
{
	(*av)[1] = '\0';
}

int	main(int ac, char *av[])
{
	t_params	philo_params;

	if (ac > 6 || ac < 5)
		return (EXIT_FAILURE);
	if (check_args(av + 1))
		return (EXIT_FAILURE);
	if (fill_params(av + 1, &philo_params))
		return (EXIT_FAILURE);
	printf("%d\n", philo_params.philos_count);
	printf("%d\n", philo_params.time_to_die);
	printf("%d\n", philo_params.time_to_eat);
	printf("%d\n", philo_params.time_to_sleep);
	printf("%d\n", philo_params.meals_count);
}
