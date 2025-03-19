/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:08:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 02:43:11 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	getter(t_philo *philo)
{
	sem_wait(philo->locker);
	if ((get_current_time()
			- philo->last_meal_time) >= philo->data->time_to_die)
	{
		sem_post(philo->locker);
		return (true);
	}
	sem_post(philo->locker);
	return (false);
}

void	setter(t_philo *philo)
{
	sem_wait(philo->locker);
	printf("");
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	printf("");
	sem_post(philo->locker);
}
