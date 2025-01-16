/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_t_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:14:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 11:59:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_list	*list_dup(t_list *list)
{
	t_list	*new_list;
	t_list	*node_copy;

	if (!list)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		node_copy = create_t_list_node(list->line);
		if (!node_copy)
			return (clear_t_list_list(new_list), NULL);
		add_back_t_list(&new_list, node_copy);
		list = list->next;
	}
	return (new_list);
}
