/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:12:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 18:06:04 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell_bonus.h"
#include <stdlib.h>

int	init_shell(t_shell *shell, char **envp)
{
	shell->env = init_env(envp);
	if (!shell->env)
		return (1);
	shell->last_status = 0;
	shell->path = ft_split(get_env_value(shell->env, "PATH"), ':');
	shell->parser = NULL;
	shell->running = 1;
	return (0);
}

int	execute_ast_node(t_ast *node, t_shell *shell)
{
	t_op	*op;

	if (!node)
		return (1);
	if (node->node->type == CMD)
		return (execute_command((t_cmd *)node->node->p_token, shell));
	else if (node->node->type == OP)
	{
		op = (t_op *)node->node->p_token;
		if (op->type == OP_PIPE)
			return (handle_pipe(node, shell));
		else if (op->type == OP_AND)
			return (handle_and(node, shell));
		else if (op->type == OP_OR)
			return (handle_or(node, shell));
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	if (init_shell(&shell, envp) != 0)
		return (1);
	shell_loop(&shell);
	cleanup_shell(&shell);
	printf("exit\n");
	return (shell.last_status);
}
