/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:23:06 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/19 16:45:00 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	wild_match(const char *input, const char *pattern)
{
	if (*pattern == '\0')
		return (*input == '\0');
	if (*pattern == '*')
	{
		while (*(pattern + 1) == '*')
			pattern++;
		if (*(pattern + 1) == '\0')
			return (1);
		while (*input != '\0')
		{
			if (wild_match(input, pattern + 1))
				return (1);
			input++;
		}
		return (wild_match(input, pattern + 1));
	}
	if (*input != '\0' && (*pattern == *input))
		return (wild_match(input + 1, pattern + 1));
	return (0);
}

t_entry	*filter_entries_by_pattern(t_entry *current, const char *pattern)
{
	t_entry	*new_list;
	char	*tmp;
	t_entry	*new_entry;

	new_list = NULL;
	while (current)
	{
		if (!(pattern[0] == '*' && pattern[1] != '.' && *current->value == '.'))
		{
			tmp = remove_quotes((char *)pattern);
			if (wild_match(current->value, tmp))
			{
				new_entry = create_entry(current->value);
				if (!new_entry)
					return (NULL);
				add_back_entry(&new_list, new_entry);
			}
			free(tmp);
		}
		current = current->next;
	}
	return (new_list);
}
