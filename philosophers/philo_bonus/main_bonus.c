/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:16:48 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/18 02:11:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo_bonus.h"
#include <sys/semaphore.h>

static bool	parser(int ac, char **av, t_data *data)
{
	if (ac > 6 || ac < 5)
		return (false);
	if (check_args(av + 1))
		return (false);
	if (fill_params(av + 1, data))
		return (false);
	if (check_params(data))
		return (false);
	return (true);
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philos;

	if (!parser(ac, av, &data))
		return (EXIT_FAILURE);
	init_sems(&data);
	if (data.death == SEM_FAILED || data.forks == SEM_FAILED
		|| data.write == SEM_FAILED || data.start == SEM_FAILED)
		return (EXIT_FAILURE);
	philos = init_philos(&data);
	if (!philos)
		return (EXIT_FAILURE);
	start_simulation(philos, &data);
	return (0);
}
