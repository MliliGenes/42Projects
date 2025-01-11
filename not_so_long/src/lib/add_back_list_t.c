/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_list_t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:20:37 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 01:26:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	add_back_list_t(list_t *head, list_t *new_node)
{
	if (!new_node)
		return ;
	if (!head)
	{
		head = new_node;
		return ;
	}
	while (head->next)
		head = head->next;
	head = new_node;
}
