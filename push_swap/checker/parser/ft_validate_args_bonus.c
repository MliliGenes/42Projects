/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:27:16 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 10:11:31 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	ft_validate_args(char **num)
{
	int	i;

	while (*num)
	{
		i = 0;
		if ((*num)[i] == '+' || (*num)[i] == '-')
			i++;
		if (!(*num)[i])
			return (0);
		while ((*num)[i] && (*num)[i] >= '0' && (*num)[i] <= '9')
			i++;
		if ((*num)[i] != '\0')
			return (0);
		num++;
	}
	return (1);
}
