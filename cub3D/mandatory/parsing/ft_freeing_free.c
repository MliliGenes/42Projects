/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeing_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:53:56 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:21:16 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	free_help(t_utils *utils)
{
	ft_freeing(utils->no);
	ft_freeing(utils->so);
	ft_freeing(utils->ea);
	ft_freeing(utils->we);
	ft_freeing(utils->f);
	ft_freeing(utils->c);
	free(utils);
}

void	parsiixx_freex(t_map *parse)
{
	free(parse->north_texture_path);
	free(parse->south_texture_path);
	free(parse->east_texture_path);
	free(parse->west_texture_path);
	free(parse);
}

void	ft_map_parse_free(t_map *parse)
{
	if (parse->east_texture_path)
		free(parse->east_texture_path);
	if (parse->north_texture_path)
		free(parse->north_texture_path);
	if (parse->south_texture_path)
		free(parse->south_texture_path);
	if (parse->west_texture_path)
		free(parse->west_texture_path);
	free(parse);
}

void	ft_utils_free(t_utils *utils)
{
	ft_freeing(utils->c);
	ft_freeing(utils->f);
	ft_freeing(utils->ea);
	ft_freeing(utils->we);
	ft_freeing(utils->so);
	ft_freeing(utils->no);
	free(utils);
}

void	ft_freeing(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
