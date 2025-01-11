/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_t_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:14:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 09:27:12 by sel-mlil         ###   ########.fr       */
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
		node_copy = malloc(sizeof(list_t));
		if (!node_copy)
			return (clear_list_t_list(new_list), NULL);
		node_copy->line = ft_strdup(list->line);
		if (!node_copy->line)
			return (clear_list_t_list(new_list), free(node_copy), NULL);
		add_back_list_t(&new_list, node_copy);
		list = list->next;
	}
	return (new_list);
}
