/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 05:48:10 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 06:34:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	search_in_map(list_t *map, char to_find)
{
	int	found;
	int	i;

	found = 0;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == to_find)
				found++;
			i++;
		}
		map = map->next;
	}
	return (found);
}
