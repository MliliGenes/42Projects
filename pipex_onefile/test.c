/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:19:32 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/14 09:51:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	int		ii;

	if (!big)
		return (NULL);
	i = 0;
	while (big[i])
	{
		ii = 0;
		while (little[ii] && big[i + ii] == little[ii])
			ii++;
		if (!little[ii])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, char sep)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_strdup(""));
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!ptr)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	ptr[j++] = sep;
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

static int	word_count(char *s, char sep)
{
	int	i;
	int	in_word;
	int	cp;

	i = 0;
	in_word = 0;
	cp = 0;
	while (s[i])
	{
		if (s[i] == sep)
		{
			in_word = 0;
		}
		else if (s[i] != sep && in_word == 0)
		{
			in_word = 1;
			cp++;
		}
		i++;
	}
	return (cp);
}

void	*free_arr(char **arr, int last_index)
{
	while (--last_index >= 0)
		free(arr[last_index]);
	free(arr);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**filling_arr(char c, const char *s, char **arr, int words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		arr[i] = ft_substr(s, (unsigned int)start, (size_t)(end - start));
		if (!arr[i])
			return (free_arr(arr, i));
		start = end + 1;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**splitted;

	if (!s)
		return (NULL);
	if (!*s)
	{
		splitted = (char **)malloc(sizeof(char *));
		if (!splitted)
			return (NULL);
		splitted[0] = NULL;
		return (splitted);
	}
	words = word_count((char *)s, c);
	splitted = (char **)malloc((words + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	return (filling_arr(c, s, splitted, words));
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

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		i++;
	free_arr(paths, i);
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
	return (true);
}

void	closing_io(int in, int out)
{
	close(in);
	close(out);
}

void	redirect_io(t_pipe *pipe_x, int cmd_index)
{
	if (cmd_index == 0)
	{
		dup2(pipe_x->infile_fd, STDIN_FILENO);
		close(pipe_x->infile_fd);
	}
	else
	{
		dup2(pipe_x->prev_pipe, STDIN_FILENO);
		close(pipe_x->prev_pipe);
	}
	if (cmd_index == pipe_x->cmds_count - 1)
	{
		dup2(pipe_x->outfile_fd, STDOUT_FILENO);
		close(pipe_x->outfile_fd);
	}
	else
	{
		dup2(pipe_x->pipe_fd[1], STDOUT_FILENO);
		close(pipe_x->pipe_fd[1]);
		close(pipe_x->pipe_fd[0]);
	}
}

static int	skip_spaces(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] == ' ')
		(*i)++;
	return (cmd[*i] != '\0');
}

static int	handle_quotes(char *cmd, int *i, char *quote_type)
{
	if (cmd[*i] == '"' || cmd[*i] == '\'')
		return (*quote_type = cmd[*i], 1);
	return (0);
}

static bool	two_quotes(char type, char *token)
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

static bool	is_there_quote(char *token)
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

static void	trim_quotes(char *token)
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

static void	set_cmd_data(t_cmd *cmd, char **tokens)
{
	cmd->args = tokens;
	cmd->cmd = tokens[0];
	cmd->path = NULL;
	cmd->valid = true;
}

bool	free_cmds_arr(t_cmd *cmds, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < index)
	{
		j = 0;
		while (cmds[i].args[j])
			j++;
		free_arr(cmds[i].args, j);
		free(cmds[i].path);
		i++;
	}
	free(cmds);
	return (false);
}

bool	set_cmds_arr(t_pipe *pipe_x, char **cmds, int cmds_count)
{
	char	**tokens;
	int		index;

	tokens = NULL;
	index = 0;
	pipe_x->cmds_count = cmds_count;
	pipe_x->cmds = malloc(sizeof(t_cmd) * (cmds_count));
	if (!pipe_x->cmds)
		return (false);
	while (index < cmds_count)
	{
		tokens = tokenize_cmd(cmds[index]);
		if (!tokens)
			return (free_cmds_arr(pipe_x->cmds, index));
		set_cmd_data(&pipe_x->cmds[index], tokens);
		index++;
	}
	return (true);
}

static void	edge_case(t_cmd *cmd)
{
	cmd->valid = access(cmd->cmd, X_OK) == 0;
	if (cmd->valid)
		cmd->path = ft_strdup(cmd->cmd);
}

bool	check_commands(t_pipe *pipe_x)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (j < pipe_x->cmds_count)
	{
		i = 0;
		while (pipe_x->paths[i])
		{
			tmp = ft_strjoin(pipe_x->paths[i], pipe_x->cmds[j].cmd, '/');
			if (!tmp)
				return (free_cmds_arr(pipe_x->cmds, pipe_x->cmds_count));
			if (access(tmp, X_OK) == 0)
				pipe_x->cmds[j].path = ft_strdup(tmp);
			free(tmp);
			i++;
		}
		if (!pipe_x->cmds[j].path)
			edge_case(&pipe_x->cmds[j]);
		j++;
	}
	return (true);
}

void	execute_command(t_pipe *pipe_x, int cmd_index)
{
	t_cmd	cmd;

	cmd = pipe_x->cmds[cmd_index];
	execve(cmd.path, cmd.args, pipe_x->envp);
	exit(1);
}

bool	is_cmds_empty(char **cmd, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < end)
	{
		j = 0;
		while (cmd[i][j] && cmd[i][j] == ' ')
			j++;
		if (!cmd[i][j])
			return (false);
		i++;
	}
	return (true);
}

// void	ll(void)
// {
// 	system("leaks -q a.out");
// }

bool	cleanup(t_pipe *pipe_x, int steps)
{
	if (steps >= 1)
		closing_io(pipe_x->infile_fd, pipe_x->outfile_fd);
	if (steps >= 2)
		free_paths(pipe_x->paths);
	if (steps >= 3)
		free_cmds_arr(pipe_x->cmds, pipe_x->cmds_count);
	return (false);
}

bool	parser(t_pipe *pipe_x, int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (false);
	if (!is_cmds_empty(argv + 2, argc - 2))
		return (false);
	if (!io_fds(pipe_x, argv[1], argv[argc - 1]))
		return (false);
	if (!check_set_paths(pipe_x, envp))
		return (cleanup(pipe_x, 1));
	if (!set_cmds_arr(pipe_x, argv + 2, argc - 3))
		return (cleanup(pipe_x, 2));
	if (!check_commands(pipe_x))
		return (cleanup(pipe_x, 2));
	return (true);
}

static bool	handle_child_process(t_pipe *pipe_x, int i)
{
	pid_t	pid;

	if (i < pipe_x->cmds_count - 1)
		if (pipe(pipe_x->pipe_fd) < 0)
			return (cleanup(pipe_x, 3));
	pid = fork();
	if (pid < 0)
		return (cleanup(pipe_x, 3));
	if (pid == 0)
	{
		redirect_io(pipe_x, i);
		execute_command(pipe_x, i);
	}
	if (i > 0)
		close(pipe_x->prev_pipe);
	if (i < pipe_x->cmds_count - 1)
	{
		close(pipe_x->pipe_fd[1]);
		pipe_x->prev_pipe = pipe_x->pipe_fd[0];
	}
	return (true);
}

bool	executor(t_pipe *pipe_x)
{
	int	i;

	i = 0;
	while (i < pipe_x->cmds_count)
	{
		if (!handle_child_process(pipe_x, i))
			return (false);
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe_x;

	if (!parser(&pipe_x, argc, argv, envp))
		return (EXIT_FAILURE);
	if (!executor(&pipe_x))
		return (EXIT_FAILURE);
	cleanup(&pipe_x, 3);
	return (EXIT_SUCCESS);
}
