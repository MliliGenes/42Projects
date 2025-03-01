/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:57:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:45:10 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	putunsigned_func(va_list args)
{
	unsigned int	u_n;
	int				count;

	u_n = va_arg(args, unsigned int);
	count = 0;
	putnbr_rec_func(u_n, &count);
	return (count);
}
