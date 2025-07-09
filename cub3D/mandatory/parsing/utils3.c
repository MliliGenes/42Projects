/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:35 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:42 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	is_valid_char(char c)
{
	const char	*valid;

	valid = "01ENWSD ";
	if (!ft_strchr(valid, c))
		return (0);
	return (1);
}

int	ft_invalid_map(char *map)
{
	int	i;

	i = index_map_p(map);
	if (ft_up_down(map, i) == -1)
		return (-1);
	if (ft_nsea(&map[i]) == -1)
		return (-1);
	return (1);
}

int	is__space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	size_t	res;
	int		i;

	res = 0;
	i = 0;
	if (!str)
		return (-1);
	while (is__space(str[i]))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}
