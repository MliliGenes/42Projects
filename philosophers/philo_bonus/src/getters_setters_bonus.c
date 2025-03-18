/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:08:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/18 02:44:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	getter(t_philo *philo)
{
	bool	flag;

	sem_wait(philo->locker);
	printf("");
	flag = (get_current_time()
			- philo->last_meal_time) > philo->data->time_to_die;
	printf("");
	sem_post(philo->locker);
	return (flag);
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
