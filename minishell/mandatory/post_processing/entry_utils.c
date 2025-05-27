/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:22:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/19 16:46:02 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	add_back_entry(t_entry **head, t_entry *new)
{
	t_entry	*tmp;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_entry	*get_all_entries(void)
{
	DIR				*dir;
	t_entry			*head;
	struct dirent	*entry;
	t_entry			*new;

	dir = opendir(".");
	if (!dir)
		return (perror("opendir"), NULL);
	head = NULL;
	entry = readdir(dir);
	while (entry)
	{
		new = create_entry(entry->d_name);
		if (!new)
		{
			free_entry_list(head);
			return (NULL);
		}
		add_back_entry(&head, new);
		entry = readdir(dir);
	}
	closedir(dir);
	return (head);
}
