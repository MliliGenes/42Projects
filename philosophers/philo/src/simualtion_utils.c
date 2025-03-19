/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:22:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/19 05:44:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	action(t_philo *philo, int type)
{
	if (type == 1)
		write_message(philo, "is thinking");
	else if (type == 2)
	{
		write_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
	else if (type == 3)
	{
		pthread_mutex_lock(philo->left_fork);
		write_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		write_message(philo, "has taken a fork");
		setter_last_meal(philo);
		write_message(philo, "is eating");
		ft_usleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->type == ODD)
		action(philo, 2);
	while (!getter(data))
	{
		action(philo, 1);
		action(philo, 3);
		action(philo, 2);
	}
	return (NULL);
}

static int	check_philosophers_status(t_philo *philos, t_data *data)
{
	int	i;
	int	done_count;

	i = 0;
	done_count = 0;
	while (i < data->philo_count)
	{
		if (data->must_eat_count != -1 && getter_is_done(&philos[i]) == true)
			done_count++;
		if (get_current_time()
			- getter_last_meal(&philos[i]) > getter_time_to_die(data))
		{
			setter(data, true);
			pthread_mutex_lock(&data->write_mutex);
			printf("%ld %d died\n", get_current_time() - data->start_time,
				philos[i].id + 1);
			pthread_mutex_unlock(&data->write_mutex);
			return (-1);
		}
		i++;
	}
	return (done_count);
}

void	monitoring(t_philo *philos, t_data *data)
{
	int	done_count;

	while (!getter(data))
	{
		done_count = check_philosophers_status(philos, data);
		if (getter(data))
			return ;
		if (data->must_eat_count != -1 && done_count >= data->philo_count)
		{
			setter(data, true);
			return ;
		}
		ft_usleep(1, NULL);
	}
}

void	start_simulation(t_data *data, t_philo *philos, int count)
{
	int	index;

	data->start_time = get_current_time();
	index = 0;
	while (index < count)
	{
		philos[index].last_meal_time = get_current_time();
		if (pthread_create(&philos[index].thread, NULL, routine,
				(void *)&philos[index]))
			return ;
		index++;
	}
	monitoring(philos, data);
	index = 0;
	while (index < count)
	{
		pthread_join(philos[index].thread, NULL);
		index++;
	}
}
