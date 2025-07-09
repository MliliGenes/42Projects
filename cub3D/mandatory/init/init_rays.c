/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:27:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/07 09:02:01 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

t_ray	*init_rays(void)
{
	t_ray	*rays;

	rays = malloc(sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	if (!rays)
		return (NULL);
	ft_memset(rays, 0, sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	return (rays);
}
