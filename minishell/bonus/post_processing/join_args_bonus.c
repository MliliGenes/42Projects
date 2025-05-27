/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:47:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/13 20:09:45 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"
#include "../include/parsing_bonus.h"

int	args_total_len(char **args)
{
	int	index;
	int	total;

	index = 0;
	total = 0;
	while (args && args[index])
	{
		total += ft_strlen(args[index]);
		index++;
	}
	return (total);
}

char	*holy_joint(char **args)
{
	char	*str;
	int		i[3];
	int		spaces;
	int		chars;

	spaces = count_args_in_cmd(args) - 1;
	chars = args_total_len(args);
	str = malloc(chars + spaces + 1);
	if (!str)
		return (NULL);
	i[2] = 0;
	i[0] = 0;
	while (args && args[i[0]])
	{
		i[1] = 0;
		while (args[i[0]][i[1]])
			str[i[2]++] = args[i[0]][i[1]++];
		if (i[0] < spaces)
			str[i[2]++] = ' ';
		free(args[i[0]]);
		i[0]++;
	}
	str[i[2]++] = 0;
	free(args);
	return (str);
}
