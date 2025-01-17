/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/17 01:45:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "lib.h"
# include "mlx42.h"
# include "structs.h"

t_game		*init_game_struct(void);
void		start_game(t_game *game);
t_map		*init_map(void);
t_assets	*init_assets(void);
t_player	*init_player(void);
void		draw_map(t_game *game);
int			put_image(void *mlx, mlx_texture_t *texture, int x, int y);
void		draw_player(t_game *game);

#endif