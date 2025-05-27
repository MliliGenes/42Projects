/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_classification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:38:00 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 17:36:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

bool	is_full_operator(t_lexer *lexer)
{
	char	c;
	char	next;

	c = lexer->current_char;
	if (c == '&' && lexer->input[lexer->pos + 1] != '&')
		return (false);
	if (c == '(' || c == ')')
		return (true);
	if (c == '|' || c == '&' || c == '<' || c == '>')
	{
		next = lexer->input[lexer->pos + 1];
		if ((c == '|' && next == '|') || (c == '&' && next == '&') || (c == '<'
				&& next == '<') || (c == '>' && next == '>'))
			return (true);
		if (c == '|' || c == '<' || c == '>')
			return (true);
	}
	return (false);
}

t_token_type	classify_operator(char *op)
{
	if (ft_strcmp(op, "|") == 0)
		return (TOKEN_PIPE);
	if (ft_strcmp(op, "||") == 0)
		return (TOKEN_OR);
	if (ft_strcmp(op, "&&") == 0)
		return (TOKEN_AND);
	if (ft_strcmp(op, "<") == 0)
		return (TOKEN_REDIR_IN);
	if (ft_strcmp(op, "<<") == 0)
		return (TOKEN_HEREDOC);
	if (ft_strcmp(op, ">") == 0)
		return (TOKEN_REDIR_OUT);
	if (ft_strcmp(op, ">>") == 0)
		return (TOKEN_APPEND);
	if (ft_strcmp(op, "(") == 0)
		return (TOKEN_PL);
	if (ft_strcmp(op, ")") == 0)
		return (TOKEN_PR);
	return (TOKEN_WORD);
}

void	classify_tokens(t_token *head)
{
	bool	is_cmd_found;

	is_cmd_found = false;
	while (head && head->type != TOKEN_EOF)
	{
		if (head->type == TOKEN_WORD && head->prev
			&& is_redir(head->prev->type))
			head->type = TOKEN_FILE;
		if (!is_cmd_found && ((head->n_index == 0 && head->type == TOKEN_WORD)
				|| (head->type == TOKEN_WORD && head->prev
					&& (is_op(head->prev->type)
						|| head->prev->type == TOKEN_PL))
				|| (head->type == TOKEN_WORD && head->prev
					&& head->prev->type == TOKEN_FILE)))
		{
			head->type = TOKEN_COMMAND;
			is_cmd_found = true;
		}
		if (head->type == TOKEN_WORD)
			head->type = TOKEN_ARG;
		if (is_op(head->type))
			is_cmd_found = false;
		head = head->next;
	}
}
