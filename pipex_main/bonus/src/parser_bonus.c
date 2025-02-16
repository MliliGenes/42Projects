/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:00:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 08:41:13 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

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
	int	fds[2];

	fds[0] = open(in_file, O_RDONLY);
	if (fds[0] == -1)
		return (false);
	fds[1] = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[1] == -1)
		return (close(fds[0]), false);
	pipe_x->infile_fd = fds[0];
	pipe_x->outfile_fd = fds[1];
	if (!ft_strcmp("/tmp/here_doc", in_file))
	{
		unlink(in_file);
		free(in_file);
	}
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

static bool	print_error(char *msg)
{
	return (write(STDERR_FILENO, msg, ft_strlen(msg)), false);
}

bool	parser(t_pipe *pipe_x, int argc, char **argv, char **envp)
{
	int		i;
	char	*input_file;

	i = 2;
	input_file = argv[1];
	if (argc < 5)
		return (print_error("Error: Too few arguments\n"));
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			return (print_error("Error: Too few arguments for here_doc\n"));
		i++;
		input_file = ft_strdup("/tmp/here_doc");
		init_here_doc(argv[2]);
	}
	if (!is_cmds_empty(argv + i, argc - 2))
		return (print_error("Error: Empty commands are not allowed\n"));
	if (!io_fds(pipe_x, input_file, argv[argc - 1]))
		return (print_error("Error: Failed to set up I/O file descriptors\n"));
	if (!check_set_paths(pipe_x, envp))
		return (cleanup(pipe_x, 1));
	if (!set_cmds_arr(pipe_x, argv + i, argc - (i + 1)))
		return (cleanup(pipe_x, 2));
	if (!check_commands(pipe_x))
		return (cleanup(pipe_x, 2));
	return (true);
}
