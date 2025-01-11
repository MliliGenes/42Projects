/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list_t_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:34:58 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 01:40:10 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	clear_list_t_list(list_t *head)
{
	list_t	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free(tmp);
	}
}
