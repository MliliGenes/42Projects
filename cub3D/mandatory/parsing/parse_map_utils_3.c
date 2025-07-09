/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:33:53 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:03 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_map	*full_members(char **map, t_utils *utils)
{
	t_map	*parse;

	parse = malloc(sizeof(t_map));
	if (!parse)
		return (NULL);
	parse->north_texture_path = ft_strdup(utils->no[1]);
	parse->south_texture_path = ft_strdup(utils->so[1]);
	parse->west_texture_path = ft_strdup(utils->we[1]);
	parse->east_texture_path = ft_strdup(utils->ea[1]);
	if (ft_check_valid_path(parse->north_texture_path,
			parse->south_texture_path, parse->west_texture_path,
			parse->east_texture_path) == -1)
	{
		ft_map_parse_free(parse);
		free_help(utils);
		return (NULL);
	}
	parse->map = map;
	return (parse);
}

int	ft_checking_close_map(char **map)
{
	if (first_line(map[0]) == -1)
		return (-1);
	if (ft_closing(map) == -1)
		return (-1);
	return (1);
}

int	ft_cheking_nsew(char **arr, int i)
{
	if (ft_count(arr[i], ' ') != 2)
		return (-1);
	return (1);
}
