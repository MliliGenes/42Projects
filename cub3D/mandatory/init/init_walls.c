/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:29:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/02 16:29:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

t_wall_hit	*init_walls(void)
{
	t_wall_hit	*walls;

	walls = malloc(sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	if (!walls)
		return (NULL);
	ft_memset(walls, 0, sizeof(t_ray) * SCREEN_WIDTH_DEFAULT);
	return (walls);
}
