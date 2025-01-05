/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:53:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:25:00 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	find_max_by_index(t_item *head)
{
	int		max_index;
	int		current_pos;
	int		max_pos;
	t_item	*current;

	if (!head)
		return (0);
	max_index = head->index;
	max_pos = 0;
	current_pos = 0;
	current = head;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (max_pos);
}
