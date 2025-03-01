/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_lower_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:56:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:44:56 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	puthex_lower_func(va_list args)
{
	unsigned long	nb;
	void			*address;
	int				count;

	address = va_arg(args, void *);
	nb = (unsigned long)address;
	count = 0;
	puthex_rec_func(nb, 0, &count);
	return (count);
}
