/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:29:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:49:50 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init_bonus.h"

t_wall_hit	*init_walls(void)
{
	t_wall_hit	*walls;

	walls = malloc(sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	if (!walls)
		return (NULL);
	ft_memset(walls, 0, sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	return (walls);
}
