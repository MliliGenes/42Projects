/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:57:47 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/13 00:12:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	putnbr_func(va_list args)
{
	int				n;
	unsigned int	u_n;
	int				count;

	n = va_arg(args, int);
	count = 0;
	if (n < 0)
	{
		put_char('-');
		count++;
		u_n = (unsigned int)(-n);
	}
	else
		u_n = (unsigned int)n;
	putnbr_rec_func(u_n, &count);
	return (count);
}
