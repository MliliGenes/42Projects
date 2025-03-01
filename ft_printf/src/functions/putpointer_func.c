/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:57:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:45:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	putpointer_func(va_list args)
{
	unsigned long	nb;
	void			*address;
	int				count;

	address = va_arg(args, void *);
	nb = (unsigned long)address;
	put_char('0');
	put_char('x');
	count = 2;
	putpointer_rec_func(nb, 0, &count);
	return (count);
}
