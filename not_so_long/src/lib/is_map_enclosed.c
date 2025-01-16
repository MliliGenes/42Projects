/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:40:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 11:59:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

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

int	is_map_enclosed(t_list *map)
{
	t_list	*tmp;
	int		map_width;

	map_width = ft_strlen(map->line);
	if (!is_all_ones(map->line))
		return (0);
	tmp = map;
	while (tmp->next)
		tmp = tmp->next;
	if (!is_all_ones(tmp->line))
		return (0);
	tmp = map;
	while (tmp)
	{
		if (tmp->line[0] != '1' || tmp->line[map_width - 1] != '1')
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
