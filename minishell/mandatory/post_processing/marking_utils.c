/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marking_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:09:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/16 01:17:08 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"
#include "../include/parsing.h"

int	whitespace_to_unprintable(char c)
{
	if (c == ' ')
		return (4);
	else if (c == '\t')
		return (5);
	else if (c == '\n')
		return (6);
	else if (c == '\r')
		return (7);
	else if (c == '\v')
		return (8);
	else if (c == '\f')
		return (9);
	else
		return (-1);
}

char	unprintable_to_whitespace(char code)
{
	if (code == 4)
		return (' ');
	else if (code == 5)
		return ('\t');
	else if (code == 6)
		return ('\n');
	else if (code == 7)
		return ('\r');
	else if (code == 8)
		return ('\v');
	else if (code == 9)
		return ('\f');
	else
		return (code);
}

char	*mark_space(char *str)
{
	bool	s_quote;
	bool	d_quote;
	int		i;

	if (!str)
		return (NULL);
	s_quote = false;
	d_quote = false;
	i = 0;
	while (str[i])
	{
		if (is_white_space(str[i]))
			str[i] = 4;
		i++;
	}
	return (str);
}

char	*reset_spaces(char *str)
{
	bool	s_quote;
	bool	d_quote;
	int		i;

	if (!str)
		return (NULL);
	s_quote = false;
	d_quote = false;
	i = 0;
	while (str[i])
	{
		str[i] = unprintable_to_whitespace(str[i]);
		i++;
	}
	return (str);
}
