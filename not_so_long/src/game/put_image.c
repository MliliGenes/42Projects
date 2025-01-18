/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:46:06 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 10:14:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

mlx_image_t	*put_image(mlx_t *mlx, mlx_texture_t *texture, int x, int y)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, img, x, y) < 0)
		exit(EXIT_FAILURE);
	return (img);
}
