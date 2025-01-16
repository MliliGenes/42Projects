/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:56:08 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 20:58:04 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_map *init_map(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    
    map->grid = NULL;
    map->width = 0;
    map->height = 0;
    
    return (map);
}