/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:25:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 08:02:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static int	list_length(list_t *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

static int	is_all_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_enclosed(list_t *map)
{
	list_t	*tmp;
	int		map_width;

	map_width = ft_strlen(map->line);
	if (!is_all_ones(map->line)) // Check first line
		return (0);
	tmp = map;
	while (tmp)
	{
		if (tmp->line[0] != '1' || tmp->line[map_width - 1] != '1')
			return (0);
		tmp = tmp->next;
	}
	tmp = map;
	while (tmp->next)
		tmp = tmp->next;
	if (!is_all_ones(tmp->line))
		return (0);
	return (1);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

static int	lexer(list_t *map)
{
	int	i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (!is_valid_char(map->line[i]))
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
	list_t	*tmp_map;

	tmp_map = create_map(path);
	if (!tmp_map)
		return (0);
	if (!is_map_rec(*map))
		return (0);
	if (!lexer(tmp_map))
		return (0);
	return (1);
}
