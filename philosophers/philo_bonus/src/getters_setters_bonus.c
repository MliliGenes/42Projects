/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:08:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/16 09:37:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	getter(t_philo *philo)
{
	bool	flag;

	sem_wait(philo->locker);
	flag = (get_current_time() - philo->last_meal_time) > philo->data->time_to_die;
	sem_post(philo->locker);
	return (flag);
}

void	setter(t_philo *philo)
{
	sem_wait(philo->locker);
	philo->last_meal_time = get_current_time();
    philo->meals_eaten++;
	sem_post(philo->locker);
}

// size_t	getter_last_meal(t_philo *philo)
// {
// 	size_t	flag;

// 	pthread_mutex_lock(&philo->meal_mutex);
// 	flag = philo->last_meal_time;
// 	pthread_mutex_unlock(&philo->meal_mutex);
// 	return (flag);
// }

// void	setter_last_meal(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->meal_mutex);
// 	philo->last_meal_time = get_current_time();
// 	philo->meals_eaten++;
// 	pthread_mutex_unlock(&philo->meal_mutex);
// }

// size_t	getter_time_to_die(t_data *data)
// {
// 	size_t	flag;

// 	pthread_mutex_lock(&data->death_mutex);
// 	flag = data->time_to_die;
// 	pthread_mutex_unlock(&data->death_mutex);
// 	return (flag);
// }
