/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:42:50 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/16 07:08:19 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins_bonus.h"

static t_env_var	**create_env_ptr_arr(t_env_var *env)
{
	int			size;
	t_env_var	*tmp;
	t_env_var	**arr;
	int			i;

	tmp = env;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(t_env_var *) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env)
	{
		arr[i++] = env;
		env = env->next;
	}
	arr[i] = NULL;
	return (arr);
}

static void	sort_env_ptr_arr(t_env_var **arr)
{
	int			i;
	int			j;
	t_env_var	*tmp;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
		{
			if (ft_strcmp(arr[i]->key, arr[j]->key) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static void	print_export(t_env_var *env_list)
{
	t_env_var	**arr;
	int			i;

	arr = create_env_ptr_arr(env_list);
	if (!arr)
		return ;
	sort_env_ptr_arr(arr);
	i = -1;
	while (arr[++i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(arr[i]->key, STDOUT_FILENO);
		if (arr[i]->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(arr[i]->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	free(arr);
}

static void	process_export_arg(char *arg, t_env_var **env_list)
{
	t_env_kv	kv;
	t_env_var	*new;

	kv = split_key_value(arg);
	if (*env_list && key_exist(*env_list, kv.key))
	{
		if (kv.has_value)
			env_update(*env_list, kv.key, kv.value);
	}
	else
	{
		new = create_env_var(kv.key, kv.value);
		add_env_back(env_list, new);
	}
	free(kv.key);
	free(kv.value);
}

int	handle_export(char **args, t_env_var **env_list)
{
	int	i;

	i = 1;
	if (!args[i])
	{
		print_export(*env_list);
		return (0);
	}
	while (args[i])
	{
		if (!is_valid_key(args[i]))
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		else
			process_export_arg(args[i], env_list);
		i++;
	}
	return (0);
}
