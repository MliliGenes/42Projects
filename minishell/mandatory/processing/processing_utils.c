/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:12:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:52:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	count_args_in_cmd(char **args)
{
	int	count;

	count = 0;
	if (!args)
		return (0);
	while (args[count])
		count++;
	return (count);
}

void	free_args_array(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	count_args(t_token *start, t_token *end)
{
	int	size;

	size = 0;
	while (start && (end == NULL || start->n_index <= end->n_index))
	{
		if (is_word(start->type))
			size++;
		start = start->next;
	}
	return (size);
}

char	**get_args(t_token *start, t_token *end)
{
	char	**args;
	int		i;

	if (!count_args(start, end))
		return (NULL);
	args = malloc(sizeof(char *) * (count_args(start, end) + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (start && (end == NULL || start->n_index <= end->n_index))
	{
		if (is_word(start->type))
		{
			args[i++] = ft_strdup(start->value);
			if (!args[i - 1])
			{
				while (--i >= 0)
					free(args[i]);
				return (free(args), NULL);
			}
		}
		start = start->next;
	}
	return (args[i] = NULL, args);
}
