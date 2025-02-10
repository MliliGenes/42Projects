/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:19:32 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/10 12:16:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>

typedef struct s_cmd
{
	char	**args;
	char	*path;
	char	*cmd;
	bool	valid;
}			t_cmd;

typedef struct s_pipe
{
	char	**paths;
	char	**envp;

	int		pipe_fd[2];
	int		prev_pipe;

	int		cmds_count;

	int		infile_fd;
	int		outfile_fd;

	t_cmd	*cmds;
}			t_pipe;

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

static void	*free_arr(char **arr, int i)
{
	while (--i >= 0)
		free(arr[i]);
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

// tools

bool	check_set_path(t_pipe *pipe_x, char **envp)
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

bool	io_fds(t_pipe *pipe_x, char *in_file, char *out_file)
{
	int	fds[2];

	fds[0] = open(in_file, O_RDONLY);
	if (fds[0] == -1)
		return (false);
	fds[1] = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[1] == -1)
		return (false);
	pipe_x->infile_fd = fds[0];
	pipe_x->outfile_fd = fds[1];
	return (true);
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
	{
		*quote_type = cmd[*i];
		(*i)++;
		return (1);
	}
	return (0);
}

static int	extract_token(char *cmd, int *i, char **tokens, int *j)
{
	int		start;
	char	quote_type;
	int		len;

	start = *i;
	quote_type = 0;
	if (handle_quotes(cmd, i, &quote_type))
		start = *i;
	while (cmd[*i] && (quote_type || cmd[*i] != ' '))
	{
		if ((cmd[*i] == '"' || cmd[*i] == '\'') && quote_type == cmd[*i])
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	if (quote_type && quote_type != cmd[*i])
	len = *i - start;
	if (quote_type)
		len--;
	tokens[*j] = ft_substr(cmd, start, len);
	if (!tokens[*j])
		return (0);
	(*j)++;
	return (1);
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

bool	set_cmds_arr(t_pipe *pipe_x, char **cmds, int cmds_count)
{
	char	**tokens;
	int		index;

	tokens = NULL;
	index = 0;
	pipe_x->cmds_count = cmds_count;
	pipe_x->cmds = malloc(sizeof(t_cmd) * (cmds_count));
	if (!pipe_x->cmds)
		return (printf("lol2"), false);
	while (index < cmds_count)
	{
		tokens = tokenize_cmd(cmds[index]);
		if (!tokens)
			return (printf("lol2"), false);
		set_cmd_data(&pipe_x->cmds[index], tokens);
		index++;
	}
	return (true);
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
				return (free(pipe_x->cmds), false);
			if (access(tmp, X_OK) == 0)
				pipe_x->cmds[j].path = tmp;
			i++;
		}
		j++;
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe_x;
	int		i;
	int		j;

	if (argc < 5)
		return (EXIT_FAILURE);
	if (!check_set_path(&pipe_x, envp))
		return (EXIT_FAILURE);
	if (!io_fds(&pipe_x, argv[1], argv[argc - 1]))
		return (EXIT_FAILURE);
	if (!set_cmds_arr(&pipe_x, argv + 2, argc - 3))
		return (printf("lol2"), EXIT_FAILURE);
	// if (!check_commands(&pipe_x))
	// 	return (printf("lol3"), EXIT_FAILURE);
	i = 0;
	while (i < pipe_x.cmds_count)
	{
		printf("Command %d:\n", i + 1);
		printf("  cmd: %s\n", pipe_x.cmds[i].cmd);
		printf("  path: %s\n", pipe_x.cmds[i].path);
		printf("  valid: %d\n", pipe_x.cmds[i].valid);
		printf("  args: ");
		if (pipe_x.cmds[i].args)
		{
			j = 0;
			while (pipe_x.cmds[i].args[j])
			{
				printf("%s ", pipe_x.cmds[i].args[j]);
				j++;
			}
		}
		printf("\n\n");
		i++;
	}
	// printf("%d\n", pipe_x.infile_fd);
	// printf("%d\n", pipe_x.outfile_fd);
	// while (*pipe_x.paths)
	// {
	// 	printf("%s\n", *pipe_x.paths);
	// 	pipe_x.paths++;
	// }
	// while (*tokens)
	// {
	// 	printf("%s\n", *tokens);
	// 	tokens++;
	// }
	return (EXIT_SUCCESS);
}
