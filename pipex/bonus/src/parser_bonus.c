/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:00:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/20 00:28:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"
#include <stdbool.h>
#include <sys/fcntl.h>

static void	print_error(char *msg, int free_)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (free_)
		free(msg);
}

bool	is_cmds_empty(char **cmd, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < end && cmd[i])
	{
		j = 0;
		while (cmd[i][j] && cmd[i][j] == ' ')
		{
			write(2, &cmd[i][j], 1);
			j++;
		}
		if (!cmd[i][j])
			return (false);
		i++;
	}
	return (true);
}

bool	io_fds(t_pipe *pipe_x, char *in_file, char *out_file)
{
	pipe_x->infile_fd = open(in_file, O_RDONLY);
	if (pipe_x->is_here_doc)
		pipe_x->outfile_fd = open(out_file, O_WRONLY | O_CREAT | O_APPEND,
				0644);
	else
		pipe_x->outfile_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe_x->infile_fd == -1 || pipe_x->outfile_fd == -1)
	{
		if (pipe_x->infile_fd == -1)
			print_error(ft_strjoin("No such file or directory:", in_file, ' '),
				1);
		if (pipe_x->outfile_fd == -1)
			print_error(ft_strjoin("Permission denied:", out_file, ' '), 1);
		return (false);
	}
	if (pipe_x->is_here_doc)
		free(in_file);
	return (true);
}

bool	check_set_paths(t_pipe *pipe_x, char **envp)
{
	char	*path;

	path = NULL;
	if (!envp)
		return (false);
	pipe_x->envp = envp;
	while (*envp)
	{
		path = ft_strstr(*envp, "PATH=");
		if (path)
		{
			pipe_x->paths = ft_split(path + 5, ':');
			if (!pipe_x->paths)
				return (false);
			return (true);
		}
		envp++;
	}
	return (false);
}

bool	parser(t_pipe *pipe_x, int argc, char **argv, char **envp)
{
	int		i;
	char	*input_file;

	i = 2;
	if (argc < 5 && i == 2)
		return (print_error("Error: Too few arguments", 0), false);
	input_file = argv[1];
	handle_here_doc(pipe_x, argv[1], &i, &input_file);
	if (argc < 6 && i == 3)
		return (print_error("Error: Too few arguments", 0), false);
	if (pipe_x->is_here_doc)
		init_here_doc(argv[2]);
	io_fds(pipe_x, input_file, argv[argc - 1]);
	if (!check_set_paths(pipe_x, envp))
		return (cleanup(pipe_x, 1));
	if (!set_cmds_arr(pipe_x, argv + i, argc - (i + 1)))
		return (cleanup(pipe_x, 2));
	if (!check_commands(pipe_x))
		return (cleanup(pipe_x, 2));
	return (true);
}
