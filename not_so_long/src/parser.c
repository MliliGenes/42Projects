/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:25:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 11:51:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include <stdio.h>

static int	lexer(list_t *map)
{
	int	i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (!(map->line[i] == '0' || map->line[i] == '1'
					|| map->line[i] == 'P' || map->line[i] == 'C'
					|| map->line[i] == 'E'))
				return (0);
			i++;
		}
		map = map->next;
	}
	return (1);
}

static int	is_map_rec(list_t *map)
{
	int	len;

	if (!map)
		return (0);
	len = ft_strlen(map->line);
	map = map->next;
	while (map)
	{
		if (ft_strlen(map->line) != (size_t)(len))
			return (0);
		map = map->next;
	}
	return (1);
}

static void	results_init(validate_t *results, list_t *map)
{
	(*results).collectibles_found = search_in_map(map, 'C');
	(*results).exits_found = search_in_map(map, 'E');
	(*results).players_found = search_in_map(map, 'P');
	(*results).line_len = ft_strlen(map->line);
}

static int	validate_results(validate_t *data)
{
	return (data->collectibles_found > 0 && data->exits_found == 1
		&& data->players_found == 1);
}

int	parser(char *path, list_t **map)
{
	list_t		*tmp_map;
	list_t		*cpy;
	play_pos_t	pos;
	validate_t	data;

	tmp_map = create_map(path);
	if (!tmp_map || !*tmp_map->line)
		return (0);
	if (!is_map_rec(tmp_map) || !lexer(tmp_map) || !is_map_enclosed(tmp_map))
		return (clear_list_t_list(tmp_map), 0);
	cpy = list_dup(tmp_map);
	if (!cpy)
		return (clear_list_t_list(tmp_map), 0);
	results_init(&data, tmp_map);
	if (!validate_results(&data))
		return (clear_list_t_list(tmp_map), 0);
	find_pos_in_map(cpy, &pos);
	flood_fill_validate(pos.line, pos.x, &data);
	clear_list_t_list(cpy);
	if (!(data.collectibles_found == 0 && data.exits_found == 0))
		return (clear_list_t_list(tmp_map), 0);
	*map = tmp_map;
	return (1);
}
