/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:16:48 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/14 02:26:27 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void	clean(t_data data, pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data.philo_count)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
	forks = NULL;
	i = 0;
	while (i < data.philo_count)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(philos);
	philos = NULL;
}

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
	t_data			data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (!parser(ac, av, &data))
		return (EXIT_FAILURE);
	forks = init_forks(data.philo_count);
	if (!forks)
		return (EXIT_FAILURE);
	philos = init_philos(&data);
	if (!philos)
		return (EXIT_FAILURE);
	assign_forks(philos, forks, data.philo_count);
	pthread_mutex_init(&data.write_mutex, NULL);
	pthread_mutex_init(&data.locker_mutex, NULL);
	pthread_mutex_init(&data.death_mutex, NULL);
	pthread_mutex_init(&data.test_mutex, NULL);
	start_simulation(&data, philos, data.philo_count);
	clean(data, forks, philos);
	return (EXIT_SUCCESS);
}
