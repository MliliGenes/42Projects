/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:09:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/20 16:28:11 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_token	*handle_word(t_lexer *lexer)
{
	t_token	*token;
	char	*value;
	int		start;
	int		in_single_quote;
	int		in_double_quote;

	start = lexer->pos;
	in_single_quote = 0;
	in_double_quote = 0;
	while (lexer->pos < lexer->len)
	{
		if (lexer->current_char == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (lexer->current_char == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		if (!in_single_quote && !in_double_quote
			&& (is_white_space(lexer->current_char) || is_full_operator(lexer)))
			break ;
		advance_lexer(lexer);
	}
	value = ft_strndup(lexer->input + start, lexer->pos - start);
	if (!value)
		return (NULL);
	token = create_token(TOKEN_WORD, value);
	return (token);
}

t_token	*handle_quoted(t_lexer *lexer)
{
	t_token	*token;
	char	*value;
	char	quote_type;
	int		start;

	start = lexer->pos;
	quote_type = lexer->current_char;
	advance_lexer(lexer);
	while (lexer->current_char != quote_type && lexer->pos < lexer->len)
		advance_lexer(lexer);
	if (lexer->current_char != quote_type)
		return (NULL);
	advance_lexer(lexer);
	while (lexer->current_char && !is_white_space(lexer->current_char)
		&& !is_full_operator(lexer))
		advance_lexer(lexer);
	value = ft_strndup(lexer->input + start, lexer->pos - start);
	if (!value)
		return (NULL);
	token = create_token(TOKEN_WORD, value);
	return (token);
}

// rm on mandatory
char	*extract_operator(t_lexer *lexer, int *op_length)
{
	char	op[3];

	op[0] = lexer->current_char;
	op[1] = 0;
	op[2] = 0;
	if (lexer->pos + 1 < lexer->len)
	{
		op[1] = lexer->input[lexer->pos + 1];
		if ((op[0] == '>' && op[1] == '>') || (op[0] == '<' && op[1] == '<'))
			*op_length = 2;
		else
		{
			*op_length = 1;
			op[1] = '\0';
		}
	}
	else
		*op_length = 1;
	return (ft_strndup(op, *op_length));
}

t_token	*handle_operator(t_lexer *lexer)
{
	int		op_len;
	t_token	*token;
	char	*op_str;

	op_str = extract_operator(lexer, &op_len);
	if (!op_str)
		return (NULL);
	advance_lexer(lexer);
	if (op_len == 2)
		advance_lexer(lexer);
	token = create_token(classify_operator(op_str), op_str);
	if (!token)
		free(op_str);
	return (token);
}
