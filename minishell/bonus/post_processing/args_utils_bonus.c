/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:12:23 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/18 02:42:55 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"

void	update_quote_status(char c, bool *in_single, bool *in_double)
{
	if (c == '\'' && !(*in_double))
		*in_single = !(*in_single);
	else if (c == '"' && !(*in_single))
		*in_double = !(*in_double);
}

void	update_quote_status_new(char c, bool *in_single, bool *in_double)
{
	if (c == 1 && !(*in_double))
		*in_single = !(*in_single);
	else if (c == 2 && !(*in_single))
		*in_double = !(*in_double);
}

bool	is_in_quote(bool in_single, bool in_double)
{
	return (in_single || in_double);
}
