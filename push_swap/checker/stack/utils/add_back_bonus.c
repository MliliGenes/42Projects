/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:42:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 10:11:44 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker.h"

void	add_back(t_item *head, t_item *new_item)
{
	if (!head || !new_item)
		return ;
	while (head->next)
		head = head->next;
	head->next = new_item;
	new_item->prev = head;
}
