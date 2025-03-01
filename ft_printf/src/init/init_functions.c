/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:51:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:45:27 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_function_entry	*init_functions(void)
{
	t_function_entry	*head;

	head = NULL;
	add_back(&head, new_node('c', (int (*)(va_list))put_char_func));
	add_back(&head, new_node('s', (int (*)(va_list))put_str_func));
	add_back(&head, new_node('d', (int (*)(va_list))putnbr_func));
	add_back(&head, new_node('i', (int (*)(va_list))putnbr_func));
	add_back(&head, new_node('p', (int (*)(va_list))putpointer_func));
	add_back(&head, new_node('u', (int (*)(va_list))putunsigned_func));
	add_back(&head, new_node('x', (int (*)(va_list))puthex_lower_func));
	add_back(&head, new_node('X', (int (*)(va_list))puthex_upper_func));
	return (head);
}
