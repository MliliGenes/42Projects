/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:17:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/10 01:41:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*init_forks(int count)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * count);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	assign_forks(t_philo *philos, pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % count];
		i++;
	}
}

void	create_philo(t_philo *philo, t_data *data, int index)
{
	philo->id = index;
	philo->type = index % 2;
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->data = data;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	pthread_mutex_init(&philo->meal_mutex, NULL);
	philo->last_meal_time = get_current_time();
}

t_philo	*init_philos(t_data *data)
{
	int index;
	t_philo *philos_arr;

	philos_arr = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos_arr)
		return (NULL);
	index = 0;
	while (index < data->philo_count)
	{
		create_philo(&philos_arr[index], data, index);
		index++;
	}
	return (philos_arr);
}