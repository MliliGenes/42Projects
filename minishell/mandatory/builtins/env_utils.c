/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:16:18 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/14 08:16:59 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

t_env_var	*handle_empty_env(void)
{
	t_env_var	*head;
	char		*cwd;

	head = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd)
		add_env_back(&head, create_env_var("PWD", cwd));
	add_env_back(&head, create_env_var("OLDPWD", NULL));
	add_env_back(&head, create_env_var("PATH",
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"));
	free(cwd);
	return (head);
}

void	free_env_list(t_env_var *head)
{
	t_env_var	*current;
	t_env_var	*next;

	current = head;
	while (current)
	{
		next = current->next;
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
