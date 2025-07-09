/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:27:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:49:50 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init_bonus.h"

t_ray	*init_rays(void)
{
	t_ray	*rays;

	rays = malloc(sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	if (!rays)
		return (NULL);
	ft_memset(rays, 0, sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	return (rays);
}
