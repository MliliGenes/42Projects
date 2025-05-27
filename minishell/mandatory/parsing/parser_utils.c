/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:37:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/29 13:00:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	get_op_precedence(t_ready_token *token)
{
	t_op_type	op_type;

	op_type = ((t_op *)token->p_token)->type;
	if (op_type == OP_AND || op_type == OP_OR)
		return (1);
	else if (op_type == OP_PIPE)
		return (2);
	else if (op_type == OP_PAREN_L || op_type == OP_PAREN_R)
		return (0);
	return (-1);
}

bool	check_input(char *input)
{
	if (check_quotes_balance(input) == 1)
		return (print_syntax_error("'", UNBALANCED_QUOTES), 1);
	if (check_quotes_balance(input) == 2)
		return (print_syntax_error("\"", UNBALANCED_QUOTES), 1);
	if (check_parenthesis_balance(input) == 1)
		return (print_syntax_error("(", UNBALANCED_PARENS), 1);
	if (check_parenthesis_balance(input) == 2)
		return (print_syntax_error(")", UNBALANCED_PARENS), 1);
	return (0);
}
