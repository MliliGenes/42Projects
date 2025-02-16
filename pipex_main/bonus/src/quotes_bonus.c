/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:38:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 02:37:18 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	handle_quotes(char *cmd, int *i, char *quote_type)
{
	if (cmd[*i] == '"' || cmd[*i] == '\'')
		return (*quote_type = cmd[*i], 1);
	return (0);
}

bool	two_quotes(char type, char *token)
{
	int	i;
	int	how_many;

	i = 0;
	how_many = 0;
	while (token[i])
	{
		if (token[i] == type)
			how_many++;
		i++;
	}
	return (how_many == 2);
}

bool	is_there_quote(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '"' || token[i] == '\'')
			return (true);
		i++;
	}
	return (false);
}

void	trim_quotes(char *token)
{
	int		i;
	int		j;
	char	quote_type;

	if (!token || !is_there_quote(token))
		return ;
	i = 0;
	j = 0;
	quote_type = 0;
	while (token[i])
	{
		if ((token[i] == '"' || token[i] == '\'') && !quote_type)
			quote_type = token[i++];
		else if (token[i] == quote_type)
			i++;
		else
			token[j++] = token[i++];
	}
	token[j] = '\0';
}
