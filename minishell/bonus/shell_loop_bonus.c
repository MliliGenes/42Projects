/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:46:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 19:37:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell_bonus.h"

char	*prompt_stderr(const char *prompt)
{
	int		stdout_save;
	char	*input;

	stdout_save = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	input = readline(prompt);
	dup2(stdout_save, STDOUT_FILENO);
	close(stdout_save);
	return (input);
}

static int	handle_here_docs(t_shell *shell)
{
	int	status;

	status = open_here_docs(shell->parser->postfix_note);
	if (status)
		shell->last_status = status;
	return (status);
}

static bool	parse_and_execute(t_shell *shell)
{
	shell->parser = parse_input(shell->input);
	if (!shell->parser || !shell->parser->holy_tree)
	{
		shell->last_status = 2;
		return (true);
	}
	if (handle_here_docs(shell) != 0)
		return (true);
	shell->last_status = execute_ast_node(shell->parser->holy_tree, shell);
	return (true);
}

static bool	process_input(t_shell *shell)
{
	shell->input = prompt_stderr(PROMPT);
	if (!shell->input)
		return (false);
	if (*shell->input)
	{
		add_history(shell->input);
		if (!parse_and_execute(shell))
			return (false);
	}
	cleanup_iteration(shell);
	return (shell->running);
}

void	shell_loop(t_shell *shell)
{
	setup_signals();
	while (shell->running)
	{
		if (!process_input(shell))
			break ;
	}
}
