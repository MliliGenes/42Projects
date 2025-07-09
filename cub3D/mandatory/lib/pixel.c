/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:30:23 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/02 16:30:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

uint32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// ! DEGUG
// void	draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	dx = abs(x1 - x0);
// 	dy = abs(y1 - y0);
// 	sx = (x0 < x1) ? 1 : -1;
// 	sy = (y0 < y1) ? 1 : -1;
// 	err = dx - dy;
// 	while (1)
// 	{
// 		x0 < (int)img->width &&y0 < (int)img->height ? mlx_put_pixel(img, x0,
// 			y0, color) : NULL;
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }
