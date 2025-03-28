/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:17:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 06:17:58 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	create_philo(t_philo *philo, t_data *data, int index)
{
	philo->data = data;
	philo->id = index;
	philo->type = index % 2;
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->name = ft_strjoin("/philo_", ft_itoa(index + 1));
	sem_unlink(philo->name);
	philo->locker = sem_open(philo->name, O_CREAT, 0644, 1);
	if (philo->locker == SEM_FAILED)
		return (false);
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
