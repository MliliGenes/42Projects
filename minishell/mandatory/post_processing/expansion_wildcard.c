/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:25:28 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/19 16:45:46 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static char	**copy_values_to_array(t_entry *head, int count)
{
	char	**values;
	t_entry	*current;
	int		i;

	values = (char **)malloc(sizeof(char *) * (count + 1));
	if (!values)
		return (NULL);
	current = head;
	i = 0;
	while (i < count)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	values[i] = NULL;
	return (values);
}

static void	perform_bubble_sort(char **values, int count)
{
	int		i;
	int		j;
	char	*temp;
	int		sorted;

	i = 0;
	sorted = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(values[j], values[j + 1]) > 0)
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
				sorted = 1;
			}
			j++;
		}
		if (!sorted)
			break ;
		i++;
	}
}

static void	reconstruct_list(t_entry *head, char **values, int count)
{
	t_entry	*current;
	int		i;

	current = head;
	i = 0;
	while (i < count)
	{
		current->value = values[i];
		current = current->next;
		i++;
	}
}

int	sort_entries_bubble(t_entry *head)
{
	char	**values;
	int		count;
	t_entry	*current;

	if (!head || !head->next)
		return (0);
	current = head;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	values = copy_values_to_array(head, count);
	if (!values)
		return (-1);
	perform_bubble_sort(values, count);
	reconstruct_list(head, values, count);
	free(values);
	return (0);
}

char	*expand_wildcard(char *arg)
{
	t_entry	*entries;
	t_entry	*tmp;
	char	*result;

	if (!arg)
		return (NULL);
	entries = get_all_entries();
	if (!entries || sort_entries_bubble(entries) < 0)
		return (arg);
	tmp = entries;
	entries = filter_entries_by_pattern(entries, arg);
	free_entry_list(tmp);
	if (!entries)
		return (arg);
	result = join_entries(entries);
	free_entry_list(entries);
	free(arg);
	return (result);
}
