/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_t_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:11:21 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 06:47:32 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

list_t	*create_list_t_node(char *line)
{
	list_t	*tmp;

	tmp = malloc(sizeof(list_t));
	if (!tmp)
		return (NULL);
    tmp->line = line;
    tmp->next = NULL;
    return (tmp);
}
