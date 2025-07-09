/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:27:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/07 17:45:21 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

uint32_t	get_pixel(const uint8_t *texture_pixels, size_t base_offset)
{
	t_pixel	pixel;

	pixel.r = texture_pixels[base_offset + 0];
	pixel.g = texture_pixels[base_offset + 1];
	pixel.b = texture_pixels[base_offset + 2];
	pixel.a = texture_pixels[base_offset + 3];
	return (ft_pixel(pixel.r, pixel.g, pixel.b, pixel.a));
}

void	fill_single_row_pixels(uint32_t *row_arr, mlx_texture_t *texture,
		size_t row_idx)
{
	size_t	x;
	size_t	base;

	x = 0;
	while (x < texture->width)
	{
		base = (row_idx * texture->width * 4) + (x * 4);
		row_arr[x] = get_pixel(texture->pixels, base);
		x++;
	}
}

void	mlx_text_to_arr(mlx_texture_t *texture, t_texture *texture_data)
{
	uint32_t	**arr;
	size_t		j;

	if (!texture || !texture_data)
		return ;
	arr = alloc_textures(texture, texture_data);
	if (!arr)
		return ;
	j = 0;
	while (j < texture->height)
	{
		fill_single_row_pixels(arr[j], texture, j);
		j++;
	}
	texture_data->arr = arr;
	mlx_delete_texture(texture);
}

bool	init_textures(t_game *game)
{
	t_map			*map;
	t_init_textures	t;

	map = game->map_data;
	t.north = mlx_load_png(map->north_texture_path);
	t.south = mlx_load_png(map->south_texture_path);
	t.west = mlx_load_png(map->west_texture_path);
	t.east = mlx_load_png(map->east_texture_path);
	t.door = mlx_load_png("imgs/door.png");
	if (!t.north || !t.south || !t.west || !t.east || !t.door)
		return (false);
	mlx_text_to_arr(t.north, &game->walls_textures[0]);
	mlx_text_to_arr(t.south, &game->walls_textures[1]);
	mlx_text_to_arr(t.west, &game->walls_textures[2]);
	mlx_text_to_arr(t.east, &game->walls_textures[3]);
	mlx_text_to_arr(t.door, &game->walls_textures[4]);
	return (true);
}
