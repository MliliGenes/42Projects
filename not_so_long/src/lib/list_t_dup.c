/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_t_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:14:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 09:19:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

static void link_back(list_t **list)
{
    list_t *current;
    list_t *tmp;
    
    current = *list;
    tmp = NULL;
    while (current)
    {
        current->prev = tmp;
        tmp = current;
        current = current->next;
    }
}

list_t  *list_dup(list_t *list)
{
    list_t  *new_list;
    list_t  *current;
    list_t  *temp;

    if (!list)
        return (NULL);
    new_list = NULL;
    current = list;
    while (current)
    {
        temp = malloc(sizeof(list_t));
        if (!temp)
            return (clear_list_t_list(new_list), NULL);
        temp->line = ft_strdup(current->line);
        if (!temp->line)
            return (clear_list_t_list(new_list), NULL);
        temp->next = new_list;
        new_list = temp;
        current = current->next;
    }

    return (new_list);
}
