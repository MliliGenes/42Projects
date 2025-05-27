/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:19:45 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/16 07:08:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/execution.h"

int	is_builtin(char *cmd)
{
	return (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "export") == 0 || ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "exit") == 0);
}

int	execute_builtin(t_cmd *cmd, t_shell *shell)
{
	if (!cmd || !cmd->cmd)
		return (1);
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		return (handle_cd(cmd->args, shell->env));
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		handle_unset(cmd->args, &shell->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		return (handle_export(cmd->args, &shell->env));
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		handle_env(shell->env);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		handle_echo(cmd->args);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		handle_pwd();
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		return (handle_exit(cmd->args, shell));
	else
		return (1);
	return (0);
}

int	execute_builtins_with_redir(t_cmd *cmd, t_shell *shell)
{
	int	saved_stdin;
	int	saved_stdout;
	int	result;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	if (cmd->redirs)
	{
		if (apply_redirections(cmd, shell) != 0)
		{
			dup2(saved_stdin, STDIN_FILENO);
			dup2(saved_stdout, STDOUT_FILENO);
			close(saved_stdin);
			close(saved_stdout);
			return (1);
		}
	}
	result = execute_builtin(cmd, shell);
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	return (result);
}
