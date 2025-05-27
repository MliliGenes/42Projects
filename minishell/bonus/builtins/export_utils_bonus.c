/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:44:49 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/07 16:57:23 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

int	is_valid_key(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

t_env_kv	split_key_value(char *arg)
{
	t_env_kv	kv;
	int			i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	kv.key = ft_substr(arg, 0, i);
	if (arg[i] == '=')
	{
		kv.value = ft_substr(arg, i + 1, ft_strlen(arg));
		kv.has_value = 1;
	}
	else
	{
		kv.value = NULL;
		kv.has_value = 0;
	}
	return (kv);
}

int	key_exist(t_env_var *env_list, char *key)
{
	t_env_var	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
