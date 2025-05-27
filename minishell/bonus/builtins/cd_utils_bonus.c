/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:32:26 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/13 19:59:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

char	*get_env_value(t_env_var *env_list, char *key)
{
	t_env_var	*current;

	if (!env_list)
		return (NULL);
	current = env_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	print_cd_error(char *prefix, char *path, char *message)
{
	(void)prefix;
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	if (path)
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(message, STDERR_FILENO);
}

int	update_pwd(t_env_var *env, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (0);
	env_update(env, "OLDPWD", old_pwd);
	env_update(env, "PWD", new_pwd);
	free(new_pwd);
	return (1);
}
