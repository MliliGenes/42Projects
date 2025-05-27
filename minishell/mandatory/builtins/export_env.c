/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:49:28 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/17 17:23:40 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

char	get_quotes_edges(char *str)
{
	char	quote_type;

	quote_type = 0;
	if (str)
	{
		quote_type = str[0];
		if (quote_type == '\'' || quote_type == '\"')
			return (quote_type);
	}
	return (quote_type);
}

t_env_var	*create_env_var(char *key, char *value)
{
	t_env_var	*new_node;

	new_node = malloc(sizeof(t_env_var));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	if (value)
		new_node->value = ft_strdup(value);
	else
		new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_env_back(t_env_var **env_list, t_env_var *new)
{
	t_env_var	*tmp;

	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	tmp = *env_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	env_update(t_env_var *env_list, char *key, char *value)
{
	t_env_var	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
}
