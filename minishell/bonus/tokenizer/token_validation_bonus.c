/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:51:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/29 13:00:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

int	check_quotes_balance(const char *input)
{
	int	in_single_quote;
	int	in_double_quote;
	int	i;

	in_single_quote = 0;
	in_double_quote = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (input[i] == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		i++;
	}
	if (in_single_quote)
		return (1);
	if (in_double_quote)
		return (2);
	return (0);
}

static void	skip_quotes(char c, int *quotes)
{
	if (c == '\'' && !quotes[1])
		quotes[0] = !quotes[0];
	else if (c == '"' && !quotes[0])
		quotes[1] = !quotes[1];
}

int	check_parenthesis_balance(const char *input)
{
	int	i;
	int	data[3];

	i = 0;
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	while (input[i])
	{
		skip_quotes(input[i], data);
		if (!data[0] && !data[1])
		{
			if (input[i] == '(')
				data[2]++;
			else if (input[i] == ')')
			{
				data[2]--;
				if (data[2] < 0)
					return (2);
			}
		}
		i++;
	}
	return (data[2] != 0);
}

bool	check_m_percent(char *input)
{
	int	i;
	int	in_single_quote;
	int	in_double_quote;

	i = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (input[i] == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (!in_single_quote && !in_double_quote && input[i] == '&')
		{
			if (input[i + 1] != '&')
				return (true);
			else
				i += 2;
		}
		i++;
	}
	return (false);
}

int	validate_tokens(t_token *head)
{
	while (head && head->type != TOKEN_EOF)
	{
		if (is_redir(head->type) && (!head->next
				|| head->next->type != TOKEN_WORD))
			return (print_syntax_error(head->value, REDIR_NEEDS_TARGET), 1);
		if (is_op(head->type) && head->next && is_op(head->next->type))
			return (print_syntax_error(head->value, CONSECUTIVE_OPS), 1);
		if (is_redir(head->type) && head->next && is_redir(head->next->type))
			return (print_syntax_error(head->value, CHAINED_REDIRS), 1);
		if (head->type == TOKEN_PL && head->next && (is_op(head->next->type)
				|| head->next->type == TOKEN_PR))
			return (print_syntax_error(head->value, INVALID_AFTER_PAREN), 1);
		if (head->type == TOKEN_PR && head->next && !is_op(head->next->type)
			&& head->next->type != TOKEN_PR && head->next->type != TOKEN_EOF)
			return (print_syntax_error(head->value, INVALID_SEQUENCE), 1);
		if (head->n_index > 0 && head->type == TOKEN_PL && head->prev
			&& !is_op(head->prev->type) && head->prev->type != TOKEN_PL)
			return (print_syntax_error(head->value, MISPLACED_PAREN), 1);
		if ((head->n_index == 0 && is_op(head->type)) || (is_op(head->type)
				&& head->next && head->next->type == TOKEN_EOF))
			return (print_syntax_error(head->value, PIPE_CONNECT), 1);
		head = head->next;
	}
	return (0);
}
