/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_t_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:11:21 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 11:04:20 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

list_t	*create_list_t_node(char *line)
{
	list_t	*tmp;

	tmp = malloc(sizeof(list_t));
	if (!tmp)
		return (NULL);
	tmp->line = ft_strdup(line);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
