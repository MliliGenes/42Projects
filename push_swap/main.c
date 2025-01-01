/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:06:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 00:42:12 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*int_argv;
	char	*joined_argv;
	char	**new_argv;
	int		len;

	if (argc < 2)
		return (1);
	if (argc == 2 && ft_word_count(argv[1], ' ') < 2)
		return (1);
	joined_argv = ft_holy_joint(argv);
	len = ft_word_count(joined_argv, ' ');
	if (!joined_argv)
		return (1);
	if (!ft_validate(joined_argv))
		free(joined_argv);
		return (1);
	new_argv = ft_split(joined_argv, ' ');
	free(joined_argv);
	if (!new_argv)
		return (1);
	if (!ft_validate_args(new_argv))
		ft_free_split(new_argv);
		return (1);
	int_argv = ft_str_to_int(new_argv, len);
	ft_free_split(new_argv);
	if (!int_argv)
		return (1);
}