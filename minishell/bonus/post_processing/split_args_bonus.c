/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:11:29 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/21 11:31:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"
#include "../include/parsing_bonus.h"

int	find_word_start(char *joint, int end, bool *in_single, bool *in_double)
{
	while (joint[end] && is_white_space(joint[end]) && !is_in_quote(*in_single,
			*in_double))
		end++;
	return (end);
}

int	find_word_end(char *joint, int end, bool *in_single, bool *in_double)
{
	while (joint[end] && (!is_white_space(joint[end]) || is_in_quote(*in_single,
				*in_double)))
	{
		update_quote_status_new(joint[end], in_single, in_double);
		end++;
	}
	return (end);
}

int	holy_count_words(char *str)
{
	bool	in_s_q;
	bool	in_d_q;
	bool	in_word;
	int		counter;
	int		index;

	counter = 0;
	index = 0;
	in_s_q = false;
	in_d_q = false;
	in_word = false;
	while (str && str[index])
	{
		update_quote_status_new(str[index], &in_s_q, &in_d_q);
		if (!is_white_space(str[index]) && !in_word)
		{
			in_word = true;
			counter++;
		}
		else if (!is_in_quote(in_s_q, in_d_q) && in_word
			&& is_white_space(str[index]))
			in_word = false;
		index++;
	}
	return (counter);
}

static void	*check(char **new_args, int i)
{
	if (!new_args[i])
	{
		while (i-- > 0)
		{
			free(new_args[i]);
		}
		free(new_args);
	}
	return (NULL);
}

char	**holy_split(char *joint)
{
	char	**new_args;
	int		i[3];
	bool	in_s_q;
	bool	in_d_q;

	i[1] = 0;
	i[2] = 0;
	i[0] = 0;
	in_s_q = false;
	in_d_q = false;
	new_args = malloc(sizeof(char *) * (holy_count_words(joint) + 1));
	if (!new_args)
		return (NULL);
	while (i[0] < holy_count_words(joint))
	{
		i[2] = find_word_start(joint, i[2], &in_s_q, &in_d_q);
		i[1] = i[2];
		i[2] = find_word_end(joint, i[2], &in_s_q, &in_d_q);
		new_args[i[0]] = ft_substr(joint, i[1], i[2] - i[1]);
		check(new_args, i[0]);
		i[0]++;
	}
	new_args[i[0]] = NULL;
	return (new_args);
}
