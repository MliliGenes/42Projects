/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:54:48 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/07 22:36:11 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	**ft_from_ptr_to_map(char *p, char **map, int size)
{
	t_waah	wah;

	wah.row = 0;
	wah.line = malloc(size + 1);
	while (map[wah.row] && *p)
	{
		wah.len = 0;
		while (*p && *p != '\n' && wah.len < size)
			wah.line[wah.len++] = *p++;
		wah.line[wah.len] = '\0';
		wah.line[wah.len] = '\0';
		if (*p == '\n')
			p++;
		wah.col = 0;
		wah.k = 0;
		while (wah.k < wah.len && map[wah.row][wah.col])
		{
			map[wah.row][wah.col++] = wah.line[wah.k];
			++wah.k;
		}
		wah.row++;
	}
	free(wah.line);
	return (map);
}

char	**ft_double_arr(char *ptr, int size, int start)
{
	char	**map;
	int		num_of_lines;
	int		i;

	num_of_lines = ft_countix(ptr, start) + 1;
	map = malloc((num_of_lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < num_of_lines)
	{
		map[i] = malloc(size + 1);
		i++;
	}
	map[i] = NULL;
	map = ft_fill_space(map, size);
	map = ft_from_ptr_to_map(&ptr[start], map, size);
	return (map);
}

int	ft_check_space_hh(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'D')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i
					+ 1][j] == ' ' || map[i - 1][j] == ' ')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_if_lot(char **map, int i, int j)
{
	if (map[i][j - 1] == '1' || map[i][j + 1] == '1')
	{
		if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
			return (-1);
	}
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
	{
		if (map[i][j - 1] == '1' || map[i][j + 1] == '1')
			return (-1);
	}
	return (1);
}

int	ft_up_down(char *ptr, int i)
{
	int		start;
	char	**map;
	int		size;

	i = extract_line(ptr, i);
	start = i;
	size = ft_the_big_size(ptr, i);
	map = ft_double_arr(ptr, size, start);
	if (ft_check_space_hh(map) == -1 || ft_closed_door(map) == -1)
	{
		ft_freeing(map);
		return (-1);
	}
	ft_freeing(map);
	return (1);
}
