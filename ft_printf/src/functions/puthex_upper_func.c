/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_upper_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:57:44 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:44:54 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	puthex_upper_func(va_list args)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(args, unsigned int);
	count = 0;
	puthex_rec_func(nb, 1, &count);
	return (count);
}
