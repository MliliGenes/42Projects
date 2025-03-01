/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_rec_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:03:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/09 04:59:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	putnbr_rec_func(unsigned int n, int *count)
{
	if (n >= 10)
		putnbr_rec_func(n / 10, count);
	put_char((char)((n % 10) + '0'));
	(*count)++;
}
