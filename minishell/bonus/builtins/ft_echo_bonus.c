/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:34:11 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/17 11:39:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

static void	print_echo_args(char **args, int i)
{
	int	first;

	first = 1;
	while (args[i])
	{
		if (!first)
			write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		first = 0;
		i++;
	}
}

static int	check_n_flag(char *arg)
{
	int	j;

	if (ft_strncmp(arg, "-n", 2) != 0)
		return (0);
	j = 2;
	while (arg[j] == 'n')
		j++;
	return (arg[j] == '\0');
}

void	ft_echo(char **args)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (args[i] && check_n_flag(args[i]))
	{
		n_flag = 1;
		i++;
	}
	print_echo_args(args, i);
	if (!n_flag)
		write(STDOUT_FILENO, "\n", 1);
}

void	handle_echo(char **args)
{
	if (!args)
		return ;
	if (write(STDOUT_FILENO, NULL, 0) == -1)
	{
		ft_putstr_fd("echo: write error: Bad file descriptor\n",
			STDERR_FILENO);
		return ;
	}
	ft_echo(args);
}
