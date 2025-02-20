/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:34:15 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/20 00:25:16 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"
#include <sys/fcntl.h>
#include <unistd.h>

void	handle_here_doc(t_pipe *pipe_x, char *first, int *i, char **input_file)
{
	if (ft_strcmp(first, "here_doc") == 0)
	{
		(*i)++;
		(*input_file) = ft_strdup("/tmp/here_doc");
		pipe_x->is_here_doc = true;
	}
}

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

static void	check_le_here_doc(void)
{
	if (access("/tmp/here_doc", F_OK) == 0)
		unlink("/tmp/here_doc");
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
		if (!tmp || !ft_strcmp(trimmed, limiter))
		{
			free(trimmed);
			break ;
		}
		file = ft_strjoin_(file, tmp);
		free(trimmed);
		free(tmp);
	}
	check_le_here_doc();
	fd = open("/tmp/here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, file, ft_strlen(file));
	return (free(tmp), close(fd), free(file), true);
}
