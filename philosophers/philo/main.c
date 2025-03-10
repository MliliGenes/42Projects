/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:16:48 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/10 01:35:32 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char *av[])
{
	t_data data;
	t_philo *philos;
	pthread_mutex_t *forks;

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