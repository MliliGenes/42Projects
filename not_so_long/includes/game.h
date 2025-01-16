/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 10:03:31 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "lib.h"
# include "mlx42.h"
# include "structs.h"

# ifndef GAME_NAME
#  define GAME_NAME "xSa the explorer"
# endif

game_t	*init_game_struct(void);

#endif