/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:34:28 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/17 09:50:56 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_exit_error(char *arg, char *message)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

static int	calculate_exit_status(char *arg)
{
	int	status;

	status = ft_atoi(arg) % 256;
	if (status < 0)
		status += 256;
	return (status);
}

int	handle_exit(char **args, t_shell *shell)
{
	if (!args[1])
	{
		shell->running = 0;
		shell->last_status = 0;
		return (0);
	}
	if (!is_numeric(args[1]))
	{
		print_exit_error(args[1], ": numeric argument required\n");
		shell->running = 0;
		shell->last_status = 255;
		return (shell->last_status);
	}
	if (args[2])
	{
		print_exit_error(NULL, "too many arguments\n");
		shell->last_status = 1;
		return (1);
	}
	shell->last_status = calculate_exit_status(args[1]);
	shell->running = 0;
	return (shell->last_status);
}
