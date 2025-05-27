/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:17:47 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 17:19:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	cleanup_iteration(t_shell *shell)
{
	if (shell->parser)
	{
		if (shell->parser->holy_tree)
			free_ast(shell->parser->holy_tree);
		if (shell->parser->postfix_note)
			free_ready_tokens_list(shell->parser->postfix_note);
		free(shell->parser);
		shell->parser = NULL;
	}
	if (shell->input)
		free(shell->input);
}

void	cleanup_shell(t_shell *shell)
{
	if (shell->env)
		free_env_list(shell->env);
	if (shell->path)
		free_2d(shell->path);
	rl_clear_history();
}
