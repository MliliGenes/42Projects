/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:06:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 00:38:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void ft_free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}


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

// int main(int argc, char **argv)
// {
//     int     *int_argv;
//     char    *joined_argv;
//     char    **new_argv;
//     int     len;

//     if (argc < 2)
//     {
//         fprintf(stderr, "Error: Not enough arguments.\n");
//         return (1);
//     }
//     if (argc == 2 && ft_word_count(argv[1], ' ') < 2)
//     {
//         fprintf(stderr, "Error: Single argument contains fewer than two words.\n");
//         return (1);
//     }
//     joined_argv = ft_holy_joint(argv);
//     if (!joined_argv)
//     {
//         fprintf(stderr, "Error: Failed to join arguments into a single string.\n");
//         return (1);
//     }
//     if (!ft_validate(joined_argv))
//     {
//         fprintf(stderr, "Error: Validation of joined arguments failed.\n");
//         free(joined_argv);
//         return (1);
//     }
//     new_argv = ft_split(joined_argv, ' ');
//     len = ft_word_count(joined_argv, ' ');
//     free(joined_argv);
//     if (!new_argv)
//     {
//         fprintf(stderr, "Error: Failed to split joined arguments into an array.\n");
//         return (1);
//     }
//     if (!ft_validate_args(new_argv))
//     {
//         fprintf(stderr, "Error: Validation of split arguments failed.\n");
//         // Free new_argv memory if allocated.
//         for (int i = 0; new_argv[i]; i++)
//             free(new_argv[i]);
//         free(new_argv);
//         return (1);
//     }
//     for (int i = 0; i < len; i++)
//         printf("Split argument %d: %s\n", i, new_argv[i]);

//     int_argv = ft_str_to_int(new_argv, len);
//     if (!int_argv)
//     {
//         fprintf(stderr, "Error: Conversion of arguments to integers failed.\n");
//         for (int i = 0; new_argv[i]; i++)
//             free(new_argv[i]);
//         free(new_argv);
//         return (1);
//     }
//     for (int i = 0; i < len; i++)
//         printf("Integer argument %d: %d\n", i, int_argv[i]);

//     free(int_argv);
//     for (int i = 0; new_argv[i]; i++)
//         free(new_argv[i]);
//     free(new_argv);

//     return (0);
// }
