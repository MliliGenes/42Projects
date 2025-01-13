/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:37:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 11:47:32 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct box
{
	mlx_t		*window;
	mlx_image_t	*image;
	mlx_image_t	*bg;
	int			size;
	int			x;
	int			y;
}				box;

// MLX_KEY_RIGHT
// MLX_KEY_LEFT
// MLX_KEY_DOWN
// MLX_KEY_UP

void	my_key_hook(void *obj)
{
	box	*box;

	box = obj;
	if (mlx_is_key_down(box->window, MLX_KEY_RIGHT))
	{

			box->x += 10;
	}
	if (mlx_is_key_down(box->window, MLX_KEY_LEFT))
	{
			box->x -= 10;
	}
	if (mlx_is_key_down(box->window, MLX_KEY_DOWN))
	{

			box->y += 10;
	}
	if (mlx_is_key_down(box->window, MLX_KEY_UP))
	{
			box->y -= 10;
	}
	mlx_delete_image(box->window, box->image);
	box->image = mlx_new_image(box->window, box->size, box->size);
	for (int y = 0; y < box->size; y++)
	{
		for (int x = 0; x < box->size; x++)
		{
			mlx_put_pixel(box->image, x, y, 0xffffffff);
		}
	}
	mlx_image_to_window(box->window, box->image, box->x, box->y);
	printf("x:%d | y:%d\n", box->x, box->y);
}

void	my_resize_hook(int32_t width, int32_t height, void *param)
{
	printf("%dx%d\n", width, height);
}

int	main(void)
{
	box				box;
	mlx_t			*mlx;
	int				center_x;
	int				center_y;
	int				radius;
	int				i;
	int				x;
	int				y;
	int				j;
	mlx_texture_t	*texture;
	mlx_image_t		*tile;

	box.size = 64;
	box.window = mlx_init(64 * 20, 64 * 10, "box moving", false);
	if (!box.window)
	{
		fprintf(stderr, "Error: mlx_init failed\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	x = 0;
	y = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 20)
		{
			if (j == 0)
			{
				texture = mlx_load_png("./edge-4.png");
			}
			else if (j == 19)
			{
				texture = mlx_load_png("./edge-3.png");
			}
			else if (i == 0)
			{
				texture = mlx_load_png("./edge-1.png");
			}
			else if (i == 9)
			{
				texture = mlx_load_png("./edge-2.png");
			}
			else
			{
				texture = mlx_load_png("./tile-1.png");
			}
			tile = mlx_texture_to_image(box.window, texture);
			mlx_image_to_window(box.window, tile, x, y);
			x += 64;
			j++;
		}
		x = 0;
		y += 64;
		i++;
	}
	box.x = 64;
	box.y = 64;
	box.image = mlx_new_image(box.window, box.size, box.size);
	for (int y = 0; y < box.size; y++)
	{
		for (int x = 0; x < box.size; x++)
		{
			mlx_put_pixel(box.image, x, y, 0xffffffff);
		}
	}
	mlx_image_to_window(box.window, box.image, box.x, box.y);
	// mlx_image_to_window(box.window, box.image, 0, 0);
	mlx_loop_hook(box.window, my_key_hook, &box);
	mlx_resize_hook(box.window, my_resize_hook, &box);
	mlx_loop(box.window);
	mlx_terminate(box.window);
	return (EXIT_SUCCESS);
}
