/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:09:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 17:57:29 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	already_exists(int index, int *int_arr, int current)
{
	while (index-- > 0)
	{
		if (current == int_arr[index])
			return (10);
	}
	return (0);
}

int	ft_str_to_int(int **int_arr, char ***strs, int ints)
{
	int		i;
	int		is_valid;
	long	tmp;

	is_valid = 1;
	i = 0;
	*int_arr = (int *)malloc(sizeof(int) * ints);
	if (!int_arr)
		return (0);
	while (i < ints)
	{
		tmp = ft_atol((*strs)[i], &is_valid);
		if (!is_valid || already_exists(i, *int_arr, tmp))
			return (free(*int_arr), 0);
		(*int_arr)[i] = tmp;
		i++;
	}
	ft_free_split(*strs);
	return (1);
}
