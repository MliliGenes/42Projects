/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:50:36 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/01 23:26:22 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "../../../include/push_swap.h"

void	sa(t_item **head);
void	sb(t_item **head);
void	ss(t_item **head_a, t_item **head_b);
void	pa(t_item **head_a, t_item **head_b);
void	pb(t_item **head_b, t_item **head_a);
void	ra(t_item **head_a);
void	rb(t_item **head_b);
void	rr(t_item **head_a, t_item **head_b);

#endif