/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:16:48 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 07:25:29 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo_bonus.h"

static void	clean(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		sem_close(philos[i].locker);
		free(philos[i].name);
		i++;
	}
	free(philos);
	philos = NULL;
	free(data->pids);
	sem_close(data->forks);
	sem_close(data->write);
	sem_close(data->stop_start);
}

void	init_sems(t_data *data)
{
	sem_unlink("/sema_forks");
	data->forks = sem_open("/sema_forks", O_CREAT, 0644, data->philo_count);
	sem_unlink("/sema_write");
	data->write = sem_open("/sema_write", O_CREAT, 0644, 1);
	sem_unlink("/sema_start");
	data->stop_start = sem_open("/sema_start", O_CREAT, 0644, 0);
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
	t_data	data;
	t_philo	*philos;

	if (!parser(ac, av, &data))
		return (EXIT_FAILURE);
	init_sems(&data);
	if (data.forks == SEM_FAILED || data.write == SEM_FAILED)
		return (EXIT_FAILURE);
	philos = init_philos(&data);
	if (!philos)
		return (EXIT_FAILURE);
	start_simulation(philos, &data);
	clean(&data, philos);
	return (EXIT_SUCCESS);
}
