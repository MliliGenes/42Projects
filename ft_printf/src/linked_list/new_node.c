/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:50:22 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:45:41 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_function_entry	*new_node(char flag, int (*function)(va_list))
{
	t_function_entry	*node;

	node = malloc(sizeof(t_function_entry));
	if (!node)
		return (NULL);
	node->flag = flag;
	node->function = function;
	node->next = NULL;
	return (node);
}
