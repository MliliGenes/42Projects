/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:08:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/10 01:10:41 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	getter(t_data *data)
{
	bool	flag;

	pthread_mutex_lock(&data->locker_mutex);
	flag = data->end_flag;
	pthread_mutex_unlock(&data->locker_mutex);
	return (flag);
}

void	setter(t_data *data, bool flag)
{
	pthread_mutex_lock(&data->locker_mutex);
	data->end_flag = flag;
	pthread_mutex_unlock(&data->locker_mutex);
}

size_t	getter_last_meal(t_philo *philo)
{
	size_t	flag;

	pthread_mutex_lock(&philo->meal_mutex);
	flag = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (flag);
}

void	setter_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

size_t	getter_time_to_die(t_data *data)
{
	size_t	flag;

	pthread_mutex_lock(&data->death_mutex);
	flag = data->time_to_die;
	pthread_mutex_unlock(&data->death_mutex);
	return (flag);
}
