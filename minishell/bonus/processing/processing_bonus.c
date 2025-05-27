/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:09:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:50:58 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

bool	extract_tokens(t_token *tokens, t_ready_token **head)
{
	t_token	*cmd_start;
	t_token	*current;

	if (!tokens)
		return (false);
	cmd_start = tokens;
	current = tokens;
	while (current && current->type != TOKEN_EOF)
	{
		if (is_op(current->type) || current->type == TOKEN_PL
			|| current->type == TOKEN_PR)
		{
			if (current != cmd_start)
				process_command_segment(cmd_start, current->prev, head);
			add_operator_to_list(current, head);
			cmd_start = current->next;
		}
		current = current->next;
	}
	if (cmd_start && cmd_start->type != TOKEN_EOF)
		process_command_segment(cmd_start, NULL, head);
	return (true);
}
