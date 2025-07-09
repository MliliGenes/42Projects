/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:48 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:29:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	parse_free(t_map *parse)
{
	ft_freeing(parse->map);
	free(parse->north_texture_path);
	free(parse->south_texture_path);
	free(parse->east_texture_path);
	free(parse->west_texture_path);
	free(parse);
}

void	clean(t_game *game)
{
	int			i;
	t_texture	text;
	int			j;

	free(game->rays);
	free(game->walls);
	free(game->player_data);
	mlx_terminate(game->mlx);
	mlx_delete_image(game->mlx, game->img_scene);
	parse_free(game->map_data);
	i = 0;
	while (i <= 4)
	{
		text = game->walls_textures[i];
		j = 0;
		while (j < (int)text.height)
			free(text.arr[j++]);
		free(text.arr);
		i++;
	}
}
