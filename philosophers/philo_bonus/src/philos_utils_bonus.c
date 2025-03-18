/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:17:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/18 00:35:01 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_sems(t_data *data)
{
	sem_unlink("/sema_forks");
	data->forks = sem_open("/sema_forks", O_CREAT, 0644, data->philo_count);
	sem_unlink("/sema_write");
	data->write = sem_open("/sema_write", O_CREAT, 0644, 1);
	sem_unlink("/sema_death");
	data->death = sem_open("/sema_death", O_CREAT, 0644, 1);
}

bool	create_philo(t_philo *philo, t_data *data, int index)
{
	philo->data = data;
	philo->id = index;
	philo->type = index % 2;
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->name = ft_strjoin("philo_", ft_itoa(index + 1));
	sem_unlink(philo->name);
	philo->locker = sem_open(philo->name, O_CREAT, 0644, 1);
	if (philo->locker == SEM_FAILED)
		return (false);
	philo->last_meal_time = get_current_time();
	return (true);
}

t_philo	*init_philos(t_data *data)
{
	int		index;
	t_philo	*philos_arr;

	philos_arr = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos_arr)
		return (NULL);
	index = 0;
	while (index < data->philo_count)
	{
		if (!create_philo(&philos_arr[index], data, index))
		{
			free(philos_arr);
			return (NULL);
		}
		index++;
	}
	return (philos_arr);
}
