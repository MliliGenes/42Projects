/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:50:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/01 16:24:57 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/moves/moves.h"
# include "./lib/parsing/parsing.h"
# include <stdlib.h>

typedef struct s_item
{
	int				val;
	int				index;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

typedef struct s_move
{
	char			*move;
}					t_move;

#endif