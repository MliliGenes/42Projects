/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:37:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/08 03:52:13 by sel-mlil         ###   ########.fr       */
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

void	my_key_hook(mlx_key_data_t keydata, void *obj)
{
	box	*box;

	box = obj;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(box->window);
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT))
		box->x += box->size;
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT))
		box->x -= box->size;
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT))
		box->y += box->size;
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT))
		box->y -= box->size;

	
	if (box->x >= 800)
		box->x = 0; 
	if (box->x < 0)
		box->x = 800 - box->size;


	if (box->y >= 800)
		box->y = 0;  
	if (box->y < 0)
		box->y = 800 - box->size;  
	
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
}

void	my_resize_hook(int32_t width, int32_t height, void *param)
{
	printf("%dx%d\n", width, height);
}

int	main(void)
{
	box		box;
	mlx_t	*mlx;
	int		center_x;
	int		center_y;
	int		radius;

	box.size = 25;
	box.window = mlx_init(800, 800, "box moving", true);
	box.image = mlx_new_image(box.window, box.size, box.size);
	box.bg = mlx_new_image(box.window, 800, 800);
	box.x = 0;
	box.y = 0;
	for (int y = 0; y < box.size; y++)
	{
		for (int x = 0; x < box.size; x++)
		{
			mlx_put_pixel(box.image, x, y, 0xffffffff);
		}
	}
	for (int y = 0; y < 800; y++)
	{
		for (int x = 0; x < 800; x++)
		{
			mlx_put_pixel(box.bg, x, y, 0x000000FF);
		}
	}
	if (!box.window)
	{
		fprintf(stderr, "Error: mlx_init failed\n");
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(box.window, box.bg, 0, 0);
	mlx_image_to_window(box.window, box.image, box.x, box.y);
	mlx_key_hook(box.window, my_key_hook, &box);
	mlx_resize_hook(box.window, my_resize_hook, &box);
	mlx_loop(box.window);
	mlx_terminate(box.window);
	return (EXIT_SUCCESS);
}
