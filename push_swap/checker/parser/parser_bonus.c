/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:05:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 10:11:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	join_and_validate(char **joined_argv, int *len, char **argv)
{
	*joined_argv = ft_holy_joint(argv);
	if (!*joined_argv)
		return (0);
	if (!ft_validate(*joined_argv))
	{
		free(*joined_argv);
		return (0);
	}
	*len = ft_word_count(*joined_argv, ' ');
	return (1);
}

static int	split_and_validate(char *joined_argv, char ***new_argv)
{
	*new_argv = ft_split(joined_argv, ' ');
	if (!new_argv)
		return (0);
	if (!ft_validate_args(*new_argv))
	{
		ft_free_split(*new_argv);
		return (0);
	}
	free(joined_argv);
	return (1);
}

int	parser(char **argv, t_item **head)
{
	char	**new_argv;
	char	*joined_argv;
	int		*int_arr;
	int		len;

	len = 0;
	joined_argv = NULL;
	if (!join_and_validate(&joined_argv, &len, argv))
		return (0);
	new_argv = NULL;
	if (!split_and_validate(joined_argv, &new_argv))
		return (0);
	int_arr = NULL;
	if (!ft_str_to_int(&int_arr, &new_argv, len))
		return (0);
	if (!ft_int_to_stack(int_arr, head, len))
		return (0);
	return (1);
}
