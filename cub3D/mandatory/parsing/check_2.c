/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:12:00 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/07 22:28:02 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	ft_the_big_size(char *ptr, int i)
{
	int	size;
	int	rev;

	size = 0;
	while (ptr[i])
	{
		rev = 0;
		if (ptr[i] == '\n')
		{
			i++;
			while (ptr[i] && ptr[i] != '\n')
			{
				rev++;
				i++;
			}
			if (rev > size)
				size = rev;
			if (ptr[i] == '\n')
				i--;
		}
		i++;
	}
	return (size);
}

int	extract_line(char *ptr, int i)
{
	int	start;

	while (ptr[i] != '\n')
		i--;
	start = i + 1;
	return (start);
}

int	ft_countix(char *ptr, int start)
{
	int	num;

	num = 0;
	while (ptr[start])
	{
		if (ptr[start] == '\n')
			num++;
		start++;
	}
	return (num);
}

char	**ft_fill_space(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = 32;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

int	ft_if_lot_2(char **map, int i, int j)
{
	if (map[i][j - 1] == '1')
	{
		if (map[i][j + 1] != '1')
			return (-1);
	}
	if (map[i][j + 1] == '1')
	{
		if (map[i][j - 1] != '1')
			return (-1);
	}
	if (map[i + 1][j] == '1')
	{
		if (map[i - 1][j] != '1')
			return (-1);
	}
	if (map[i - 1][j] == '1')
	{
		if (map[i + 1][j] != '1')
			return (-1);
	}
	return (1);
}
