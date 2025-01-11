/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:25:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 09:46:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static int	lexer(list_t *map)
{
	int	i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (!(map->line[i] == '0' || map->line[i] == '1' || map->line[i] == 'P' || map->line[i] == 'C' || map->line[i] == 'E'))
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

	len = ft_strlen(map->line);
	map = map->next;
	while (map)
	{
		if (ft_strlen(map->line) != len)
			return (0);
		map = map->next;
	}
	return (1);
}

int	parser(char *path, list_t **map)
{
	list_t		*tmp_map;
	list_t		*cpy;
	validate_t	results;

	tmp_map = create_map(path);
	if (!tmp_map)
		return (0);
	if (!is_map_rec(*map))
		return (clear_list_t_list(tmp_map), 0);
	if (!lexer(tmp_map))
		return (clear_list_t_list(tmp_map), 0);
    if (!is_map_enclosed(tmp_map))
        return (clear_list_t_list(tmp_map), 0);
	cpy = list_dup(tmp_map);
	if (!cpy)
		return (clear_list_t_list(tmp_map), 0);
	// results.collectibles_found = find_collectibles();
	// results.line_len = str_len();
	// results.found_exit = 0;
	return (1);
}
