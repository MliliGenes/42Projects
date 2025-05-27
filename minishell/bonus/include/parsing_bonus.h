/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:51:57 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/20 02:19:38 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "builtins_bonus.h"
# include "dependencies_bonus.h"
# include "lib_bonus.h"
# include "structs_bonus.h"

// MARK: - Lexer Utility Functions
t_lexer							*init_lexer(char *input);
void							advance_lexer(t_lexer *lexer);
void							skip_whitespace(t_lexer *lexer);
t_token							*get_next_token(t_lexer *lexer);
void							create_tokens_list(t_lexer *lexer,
									t_token **head);

// MARK: - Token Utility Functions
t_token							*create_token(t_token_type type, char *value);
void							add_back_token(t_token **head, t_token *node);
void							free_token(t_token *token);
void							free_token_list(t_token *head);

bool							is_white_space(char c);
bool							is_operator(char c);
bool							is_op(t_token_type type);
bool							is_redir(t_token_type type);
bool							is_word(t_token_type type);
bool							is_full_operator(t_lexer *lexer);
t_token_type					classify_operator(char *op);
void							classify_tokens(t_token *head);

// MARK: - Token Handling Utility Functions
t_token							*handle_word(t_lexer *lexer);
t_token							*handle_quoted(t_lexer *lexer);
t_token							*handle_operator(t_lexer *lexer);

// MARK: - Token Validation Utility Functions
int								check_quotes_balance(const char *input);
int								check_parenthesis_balance(const char *input);
bool							check_m_percent(char *input);
int								validate_tokens(t_token *head);

// MARK: - Redirection Processing Utility Functions
typedef struct s_redir			t_redir;
t_redir_type					token_to_redir_type(t_token_type type);
t_redir							*create_redir_node(t_redir_type type,
									char *file_or_limiter);
void							add_back_redir_node(t_redir **head,
									t_redir *node);
void							free_redirs(t_redir *redirs);
bool							has_redirections(t_token *start, t_token *end);
t_redir							*get_redirs(t_token *start, t_token *end);

// MARK: - Command Processing Utility Functions
typedef struct s_cmd			t_cmd;
t_cmd							*create_cmd_node(char **args, t_redir *redirs);
t_cmd							*extract_cmd_data(t_token *start, t_token *end);
bool							process_command_segment(t_token *start,
									t_token *end, t_ready_token **head);

// MARK: - Operator Processing Utility Functions
typedef struct s_op				t_op;
typedef struct s_ready_token	t_ready_token;
t_op_type						token_to_op_type(t_token_type type);
t_op							*create_op_node(t_op_type type);
bool							add_operator_to_list(t_token *current,
									t_ready_token **head);

// MARK: - Ready Token Utility Functions
t_ready_token					*create_ready_token_node(void *token, int type);
void							add_back_ready_token(t_ready_token **head,
									t_ready_token *node);
void							free_ready_tokens_list(t_ready_token *head);

// MARK: - General Processing Utility Functions
void							free_args_array(char **args, int count);
int								count_args(t_token *start, t_token *end);
int								count_args_in_cmd(char **args);
char							**get_args(t_token *start, t_token *end);
bool							extract_tokens(t_token *tokens,
									t_ready_token **head);

// MARK: - Parser Utility Functions
typedef struct s_parser			t_parser;
typedef struct s_ast			t_ast;
int								get_op_precedence(t_ready_token *token);
bool							check_input(char *input);
void							print_notation(t_ready_token *head);
void							print_ast(t_ast *root);

// MARK: - Shunting Yard Utility Functions
void							add_front_ops_stack(t_ready_token **head,
									t_ready_token *node);
void							push_to_postfix(t_ready_token **head,
									t_ready_token *node);
t_ready_token					*pop_infix_note(t_parser *parser);
t_ready_token					*pop_op_stack_note(t_parser *parser);
void							op_to_postfix(t_ready_token *op,
									t_parser *parser);
void							shunting_yard(t_parser *parser);

// MARK: - AST Construction Utility Functions
void							free_ast(t_ast *root);
t_ast							*post_to_tree(t_ready_token *postfix);

// MARK: - Parser Core Functions
t_parser						*init_parser(void);
t_parser						*parse_input(char *cmd_line);

#endif
