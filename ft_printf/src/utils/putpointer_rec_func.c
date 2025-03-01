/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer_rec_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:10:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/10 09:15:26 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	putpointer_rec_func(unsigned long nb, int is_toupper, int *count)
{
	char	*set_lower;
	char	*set_upper;

	set_lower = "0123456789abcdef";
	set_upper = "0123456789ABCDEF";
	if (nb >= 16)
		putpointer_rec_func(nb / 16, is_toupper, count);
	if (is_toupper != 0)
		put_char(set_upper[nb % 16]);
	else
		put_char(set_lower[nb % 16]);
	(*count)++;
}
