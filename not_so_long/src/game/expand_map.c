/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:13 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 19:04:27 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include <stdio.h>

char	**allocate_expanded_map(int width, int height, int scale)
{
	char	**expanded;
	int		i;
	int		j;

	// Allocate for the scaled height
	expanded = malloc(sizeof(char *) * (height * scale + 1));  // +1 for NULL terminator
	if (!expanded)
		return (NULL);
	i = 0;
	while (i < (height * scale))
	{
		// Allocate for the scaled width plus null terminator
		expanded[i] = calloc((width * scale + 1), sizeof(char));
		if (!expanded[i])
		{
			j = 0;
			while (j < i)
			{
				free(expanded[j]);
				j++;
			}
			free(expanded);
			return (NULL);
		}
		i++;
	}
	expanded[height * scale] = NULL;  // NULL terminate the array
	return (expanded);
}

void	expand_map_line(t_list *current_node, char **expanded_map, 
						int start_y, int scale)
{
	int	start_x;
	int	block_y;
	int	block_x;
	int	i;
	int	j;

	start_x = 0;
	while (current_node->line[start_x] != '\0')
	{
		block_y = start_y * scale;
		block_x = start_x * scale;
		i = 0;
		while (i < scale && (block_y + i) < (start_y + 1) * scale)
		{
			j = 0;
			while (j < scale && (block_x + j) < (start_x + 1) * scale)
			{
				expanded_map[block_y + i][block_x + j] = 
					current_node->line[start_x];
				j++;
			}
			// Add null terminator at the end of each row
			expanded_map[block_y + i][block_x + scale] = '\0';
			i++;
		}
		start_x++;
	}
}

char	**expand_map_by_scale(t_list *map, int width, int height, int scale)
{
	char	**expanded_map;
	t_list	*current_node;
	int		y;

	if (!map || width <= 0 || height <= 0 || scale <= 0)
		return (NULL);

	expanded_map = allocate_expanded_map(width, height, scale);
	if (!expanded_map)
		return (NULL);
	current_node = map;
	y = 0;
	while (current_node != NULL && y < height)
	{
		expand_map_line(current_node, expanded_map, y, scale);
		current_node = current_node->next;
		y++;
	}
	return (expanded_map);
}
