/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:17:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/03/16 09:50:55 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

sem_t	*init_forks(int count)
{
	sem_t	*sem;

	sem_unlink("/sema_forks");
	sem = sem_open("/sema_forks", O_CREAT, 0644, count);
	if (sem == SEM_FAILED)
		return (NULL);
	return (sem);
}

sem_t	*write_sem(void)
{
	sem_t	*sem;

	sem_unlink("/sema_write");
	sem = sem_open("/sema_write", O_CREAT, 0644, 1);
	if (sem == SEM_FAILED)
		return (NULL);
	return (sem);
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
