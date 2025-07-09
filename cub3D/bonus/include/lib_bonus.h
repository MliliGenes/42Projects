/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:23:36 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:52:55 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_BONUS_H
# define LIB_BONUS_H

# include "dependencies_bonus.h"
# include "structs_bonus.h"

double		deg_to_radian(double deg);
double		normalize_angle(double angle);
uint32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		*ft_memset(void *b, int c, size_t len);

#endif