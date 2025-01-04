/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:22:47 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/04 16:57:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	list_size(t_item *head)
{
	int	list_len;

	list_len = 0;
	while (head)
	{
		list_len++;
		head = head->next;
	}
	return (list_len);
}
