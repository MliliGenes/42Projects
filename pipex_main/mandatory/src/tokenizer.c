/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:36:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/15 17:01:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	skip_spaces(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] == ' ')
		(*i)++;
	return (cmd[*i] != '\0');
}

static bool	extract_token(char *cmd, int *i, char **tokens, int *j)
{
	int		start;
	char	quote_type;

	start = *i;
	quote_type = 0;
	if (handle_quotes(cmd, i, &quote_type))
	{
		start = *i;
		(*i)++;
	}
	while (cmd[*i] && (quote_type || cmd[*i] != ' '))
	{
		if ((cmd[*i] == '"' || cmd[*i] == '\'') && quote_type == cmd[*i])
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	tokens[*j] = ft_substr(cmd, start, *i - start);
	if (!tokens[*j] || (is_there_quote(tokens[*j]) && !two_quotes(quote_type,
				tokens[*j])))
		return (false);
	trim_quotes(tokens[*j]);
	return ((*j)++, true);
}

char	**tokenize_cmd(char *cmd)
{
	char	**tokens;
	int		i;
	int		j;

	if (!cmd)
		return (NULL);
	tokens = malloc(sizeof(char *) * (ft_strlen(cmd) + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (!skip_spaces(cmd, &i))
			break ;
		if (!extract_token(cmd, &i, tokens, &j))
			return (free_arr(tokens, j));
	}
	tokens[j] = NULL;
	return (tokens);
}
