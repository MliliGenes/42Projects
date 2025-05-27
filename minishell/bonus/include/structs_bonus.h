/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:20:05 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/21 08:01:16 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "dependencies_bonus.h"

typedef struct s_lexer
{
	char					*input;
	int						len;
	int						pos;
	char					current_char;
}							t_lexer;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_COMMAND,
	TOKEN_ARG,
	TOKEN_FILE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_PL,
	TOKEN_PR,
	TOKEN_EOF
}							t_token_type;

typedef struct s_token
{
	char					*value;
	t_token_type			type;
	int						n_index;
	struct s_token			*next;
	struct s_token			*prev;
}							t_token;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}							t_redir_type;

typedef struct s_redir
{
	t_redir_type			type;
	char					*file_or_limiter;
	int						here_doc_read;
	struct s_redir			*next;
}							t_redir;

typedef struct s_cmd
{
	char					**args;
	char					*cmd;
	int						fds[2];
	t_redir					*redirs;
}							t_cmd;

typedef enum e_op_type
{
	OP_PAREN_L,
	OP_PAREN_R,
	OP_PIPE,
	OP_AND,
	OP_OR
}							t_op_type;

typedef struct s_op
{
	t_op_type				type;
}							t_op;

typedef enum e_ready_token_type
{
	CMD,
	OP,
}							t_ready_token_type;

typedef struct s_ready_token
{
	t_ready_token_type		type;
	void					*p_token;
	struct s_ready_token	*next;
	struct s_ready_token	*prev;
}							t_ready_token;

typedef struct s_ast
{
	t_ready_token			*node;
	struct s_ast			*left;
	struct s_ast			*right;
}							t_ast;

typedef struct s_parser
{
	t_ready_token			*infix_note;
	t_ready_token			*ops_stack;
	t_ready_token			*postfix_note;
	t_ast					*holy_tree;
}							t_parser;

typedef struct s_env_var
{
	char					*key;
	char					*value;
	struct s_env_var		*next;
}							t_env_var;

typedef struct s_env_kv
{
	char					*key;
	char					*value;
	int						has_value;
}							t_env_kv;

typedef struct s_shell
{
	t_env_var				*env;
	int						last_status;
	char					**path;
	t_parser				*parser;
	int						running;
	char					*input;
}							t_shell;

typedef struct s_expansion
{
	char					*input;
	char					*output;
	int						s_quote;
	int						d_quote;
	int						i_index;
	int						o_index;
	int						len;
	t_shell					*shell;
}							t_expansion;

typedef struct s_file
{
	bool					bad_trip;
	bool					empty;
	bool					herdoc;
	char					*name;
	char					*limiter;
	char					*raw;
}							t_file;

typedef struct s_entry
{
	char					*value;
	int						entry_len;
	struct s_entry			*next;
}							t_entry;

#endif
