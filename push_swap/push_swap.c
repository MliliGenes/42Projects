/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:06:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/04 18:32:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	t_item	*stack_a;
	t_item	*stack_b;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	if (!parser(argv, &stack_a))
		error();
	else
	{
		sort(&stack_a, &stack_b);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		*int_argv;
// 	char	*joined_argv;
// 	char	**new_argv;
// 	int		len;

// 	if (argc < 2)
// 		return (1);
// 	if (argc == 2 && ft_word_count(argv[1], ' ') < 2)
// 		return (1);
// 	joined_argv = ft_holy_joint(argv);
// 	len = ft_word_count(joined_argv, ' ');
// 	if (!joined_argv)
// 		return (1);
// 	if (!ft_validate(joined_argv))
// 		free(joined_argv);
// 		return (1);
// 	new_argv = ft_split(joined_argv, ' ');
// 	free(joined_argv);
// 	if (!new_argv)
// 		return (1);
// 	if (!ft_validate_args(new_argv))
// 		ft_free_split(new_argv);
// 		return (1);
// 	int_argv = ft_str_to_int(new_argv, len);
// 	ft_free_split(new_argv);
// 	if (!int_argv)
// 		return (1);
// }

// int	main(int argc, char **argv)
// {
// 	int		*int_argv;
// 	char	*joined_argv;
// 	char	**new_argv;
// 	int		len;

// 	if (argc < 2)
// 	{
// 		printf("Error: Not enough arguments.\n");
// 		return (1);
// 	}

// 	if (argc == 2 && ft_word_count(argv[1], ' ') < 2)
// 	{
// 		printf("Error: Single argument has less than two words.\n");
// 		return (1);
// 	}

// 	joined_argv = ft_holy_joint(argv);
// 	if (!joined_argv)
// 	{
// 		printf("Error: Failed to join arguments.\n");
// 		return (1);
// 	}

// 	printf("Debug: Joined arguments: %s\n", joined_argv);

// 	len = ft_word_count(joined_argv, ' ');
// 	printf("Debug: Word count in joined arguments: %d\n", len);

// 	if (!ft_validate(joined_argv))
// 	{
// 		printf("Error: Validation failed for joined arguments.\n");
// 		free(joined_argv);
// 		return (1);
// 	}

// 	new_argv = ft_split(joined_argv, ' ');
// 	free(joined_argv);

// 	if (!new_argv)
// 	{
// 		printf("Error: Failed to split joined arguments.\n");
// 		return (1);
// 	}

// 	printf("Debug: Split arguments:\n");
// 	for (int i = 0; new_argv[i]; i++)
// 		printf("  [%d]: %s\n", i, new_argv[i]);

// 	if (!ft_validate_args(new_argv))
// 	{
// 		printf("Error: Validation failed for split arguments.\n");
// 		ft_free_split(new_argv);
// 		return (1);
// 	}

// 	int_argv = ft_str_to_int(new_argv, len);
// 	ft_free_split(new_argv);

// 	if (!int_argv)
// 	{
// 		printf("Error: Failed to convert arguments to integers.\n");
// 		return (1);
// 	}

// 	printf("Debug: Converted arguments to integers:\n");
// 	for (int i = 0; i < len; i++)
// 		printf("  [%d]: %d\n", i, int_argv[i]);

// 	free(int_argv);
// 	return (0);
// }