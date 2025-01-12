/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:56:15 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 06:18:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void flood_fill_validate(list_t *node, int x, validate_t *result)
{
    char current;

    if (!node || !node->line)
        return;
    if (x < 0 || x >= result->line_len)
        return;
    current = node->line[x];
    if (current == '1' || current == 'F')
        return;
    if (current == 'C')
        result->collectibles_found--;
    else if (current == 'E')
        result->exits_found--;
    node->line[x] = 'F';
    flood_fill_validate(node->prev, x, result);
    flood_fill_validate(node->next, x, result);
    flood_fill_validate(node, x - 1, result);
    flood_fill_validate(node, x + 1, result);
}
