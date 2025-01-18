/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 23:50:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "lib.h"
# include "mlx42.h"
# include "structs.h"

t_game		*init_game_struct(void);
void		start_game(t_game **game);
t_map		*init_map(void);
t_player	*init_player(void);
void		draw_map(t_game **game);
void		draw_player(t_game **game);
mlx_image_t	*put_image(mlx_t *game, mlx_texture_t *texture, int x, int y);
void		event_listener(void *game);

void		convert_map(t_game **game);
char		**expand_map_by_scale(t_list *map, int width, int height,
				int scale);
void		free_expanded_map(char **expanded, int exp_height);

t_assets	*init_assets(void);
int			init_assets_animations_up(t_assets **assets);
int			init_assets_animations_down(t_assets **assets);
int			init_assets_animations_left(t_assets **assets);
int			init_assets_animations_right(t_assets **assets);
void		*free_assets(t_assets *assets);

void		update_player(t_game *game);

#endif