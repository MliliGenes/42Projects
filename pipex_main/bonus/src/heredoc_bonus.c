/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:34:15 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 08:41:32 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static char	*trim_n(char *input)
{
	size_t	len;
	char	*output;
	size_t	i;

	len = ft_strlen(input);
	output = (char *)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = input[i];
		i++;
	}
	if (i > 0 && output[i - 1] == '\n')
		output[i - 1] = '\0';
	else
		output[i] = '\0';
	return (output);
}

bool	init_here_doc(char *limiter)
{
	char	*file;
	char	*tmp;
	char	*trimmed;
	int		fd;

	tmp = NULL;
	file = ft_strdup("");
	while (true)
	{
		write(1, "> ", 2);
		tmp = get_next_line(0);
		trimmed = trim_n(tmp);
		if (!ft_strcmp(trimmed, limiter))
		{
			free(trimmed);
			break ;
		}
		file = ft_strjoin_(file, tmp);
		free(trimmed);
		free(tmp);
	}
	fd = open("/tmp/here_doc", O_CREAT | O_WRONLY, 0644);
	write(fd, file, ft_strlen(file));
	return (free(tmp), close(fd), free(file), true);
}
