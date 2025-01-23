/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:54:43 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/22 19:56:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

static void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

void	ft_putnbr(int n)
{
	unsigned int np;

	if (n < 0)
	{
		ft_putchar('-');
		np = (unsigned int)(n * -1);
	}
	else
		np = (unsigned int)(n);
	if (np <= 9)
		ft_putchar(np + '0');
	else
	{
		ft_putnbr((np / 10));
		ft_putchar((np % 10) + '0');
	}
}