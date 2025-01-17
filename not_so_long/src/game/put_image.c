/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:46:06 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 23:58:25 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	put_image(void *mlx, mlx_texture_t *texture, int x, int y)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, img, x, y) < 0)
		exit(EXIT_FAILURE);
	return (1);
}
