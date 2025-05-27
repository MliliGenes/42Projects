/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:34:31 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/18 02:50:07 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

void	handle_pwd(void)
{
	char	*pwd;

	if (write(STDOUT_FILENO, NULL, 0) == -1)
	{
		ft_putstr_fd("pwd: write error: Bad file descriptor\n", STDERR_FILENO);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	else
		perror("getcwd");
}
