/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:27:08 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 15:40:49 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

t_lexer	*init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input = input;
	lexer->current_char = lexer->input[0];
	lexer->pos = 0;
	lexer->len = ft_strlen(input);
	return (lexer);
}

void	advance_lexer(t_lexer *lexer)
{
	if (lexer->pos < lexer->len)
	{
		lexer->pos++;
		lexer->current_char = lexer->input[lexer->pos];
	}
}

void	skip_whitespace(t_lexer *lexer)
{
	while (lexer->pos < lexer->len && is_white_space(lexer->current_char))
		advance_lexer(lexer);
}

t_token	*get_next_token(t_lexer *lexer)
{
	skip_whitespace(lexer);
	if (lexer->current_char == '\0')
		return (create_token(TOKEN_EOF, NULL));
	if (lexer->current_char == '\'' || lexer->current_char == '"')
		return (handle_quoted(lexer));
	if (is_full_operator(lexer))
		return (handle_operator(lexer));
	return (handle_word(lexer));
}

void	create_tokens_list(t_lexer *lexer, t_token **head)
{
	t_token	*token;

	while (true)
	{
		token = get_next_token(lexer);
		if (token && token->type == TOKEN_EOF)
		{
			add_back_token(head, token);
			break ;
		}
		add_back_token(head, token);
	}
}
