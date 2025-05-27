/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 04:16:25 by le-saad           #+#    #+#             */
/*   Updated: 2025/05/21 08:03:23 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "builtins.h"

char	*get_cmd_path(t_cmd *cmd, char **paths);
char	**env_to_array(t_env_var *env);
int		execute_command(t_cmd *cmd, t_shell *shell);
int		apply_redirections(t_cmd *cmd, t_shell *shell);
int		handle_ambiguous(bool quoted, bool empty, char *name, char *raw);

int		handle_redir_in(t_cmd *cmd, t_file *file);
int		handle_redir_out(t_cmd *cmd, t_file *file);
int		handle_redir_append(t_cmd *cmd, t_file *file);
int		handle_redir_heredoc(t_cmd *cmd, t_redir *redir, t_file *file,
			t_shell *shell);

int		handle_pipe(t_ast *node, t_shell *shell);
int		handle_and(t_ast *node, t_shell *shell);
int		handle_or(t_ast *node, t_shell *shell);

void	cleanup_fds(t_cmd *cmd);
void	save_std_fds(int *saved_stdin, int *saved_stdout);
void	restore_std_fds(int saved_stdin, int saved_stdout);
void	apply_fds(t_cmd *cmd);

int		execute_ast_node(t_ast *node, t_shell *shell);

int		whitespace_to_unprintable(char c);
char	unprintable_to_whitespace(char code);
char	*find_env_var(t_shell *shell, const char *key);
void	init_expansion(t_expansion *exp, char *input, t_shell *shell);
void	update_quote_state(t_expansion *exp, char current_char);
char	*holy_joint(char **args);
int		holy_count_words(char *str);
char	**holy_split(char *joint);
int		handle_exit_status(int status);
char	*expand_vars(char *input, t_shell *shell);
void	update_quote_status(char c, bool *in_single, bool *in_double);
void	update_quote_status_new(char c, bool *in_single, bool *in_double);
bool	is_in_quote(bool in_single, bool in_double);
char	*remove_quotes(char *str);
char	*mark_space(char *str);
char	*reset_spaces(char *str);
char	*mark_quotes(char *str);
char	*mark_astrestisk(char *str);
char	*reset_astrestisk(char *str);
void	update_cmd_node(t_cmd *cmd, t_shell *shell);

t_entry	*create_entry(char *value);
void	free_entry_list(t_entry *head);
void	add_back_entry(t_entry **head, t_entry *node);
t_entry	*get_all_entries(void);
char	*join_entries(t_entry *head);
int		wild_match(const char *input, const char *pattern);
t_entry	*filter_entries_by_pattern(t_entry *old, const char *pattern);
char	*expand_wildcard(char *arg);

int		open_here_docs(t_ready_token *tokens);
int		setup_pipe(int fd[2]);
void	handle_heredoc_child_process(int fd[2], char *limiter);
pid_t	create_heredoc_process(int fd[2], char *limiter);
int		wait_for_heredoc_process(pid_t pid);
int		update_heredoc_pipe(t_redir *redir, t_shell *shell);
char	*get_line(int fd);
int		empty(char *str);
int		check_path(t_cmd *path);
void	get_child_status(int *status);

void	calc_exp_len(t_expansion *exp);
void	handle_quotes(t_expansion *exp);
void	handle_status(t_expansion *exp);
bool	has_quotes(char *str);

#endif