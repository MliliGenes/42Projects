/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_t_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:14:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 11:07:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

list_t	*list_dup(list_t *list)
{
	list_t	*new_list;
	list_t	*node_copy;

	if (!list)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		node_copy = create_list_t_node(list->line);
		if (!node_copy)
			return (clear_list_t_list(new_list), NULL);
		add_back_list_t(&new_list, node_copy);
		list = list->next;
	}
	return (new_list);
}
