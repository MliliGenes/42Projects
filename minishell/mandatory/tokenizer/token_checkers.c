/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/23 11:21:08 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

bool	is_white_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_operator(char c)
{
	return (c == '|' || c == '&' || c == '<' || c == '>' || c == '('
		|| c == ')');
}

bool	is_op(t_token_type type)
{
	return (type == TOKEN_AND || type == TOKEN_OR || type == TOKEN_PIPE);
}

bool	is_redir(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

bool	is_word(t_token_type type)
{
	return (type == TOKEN_COMMAND || type == TOKEN_ARG);
}
