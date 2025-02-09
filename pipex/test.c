/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:19:32 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/09 03:41:05 by sel-mlil         ###   ########.fr       */
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
	char	*envp;

	int		pipe_fd[2];
	int		prev_pipe;

	int		cmds_count;

	int		infile_fd;
	int		outfile_fd;

	t_cmd	**cmds;
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
	while (*envp)
	{
		path = ft_strstr(*envp, "PATH=");
		if (path)
		{
			pipe_x->envp = path;
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

bool	init_commands(t_pipe *pipe_x, char **cmds, int argc)
{
	char	*tmp;
	int		i;
	int		j;

	pipe_x->cmds_count = argc - 3;
	pipe_x->cmds = malloc(sizeof(t_cmd *) * (pipe_x->cmds_count + 1));
	if (!pipe_x->cmds)
		return (false);
	pipe_x->cmds[pipe_x->cmds_count] = NULL;
	j = 0;
	while (*(cmds + 1))
	{
		i = 0;
		while (pipe_x->paths[i])
		{
			tmp = ft_strjoin(pipe_x->paths[i], *cmds, '/');
			if (!tmp)
			{
				// free the above
				return (false);
			}
			if (access("", X_OK) == 0)
			{
				pipe_x->cmds[j]->cmd
			}
		}
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe_x;

	if (!check_set_path(&pipe_x, envp))
		return (EXIT_FAILURE);
	if (!io_fds(&pipe_x, argv[1], argv[argc - 1]))
		return (EXIT_FAILURE);
	if (!init_commands(&pipe_x, argv + 2, argc - 3))
		return (EXIT_FAILURE);
	printf("%d\n", pipe_x.infile_fd);
	printf("%d\n", pipe_x.outfile_fd);
	while (*pipe_x.paths)
	{
		printf("%s\n", *pipe_x.paths);
		pipe_x.paths++;
	}	
	return (EXIT_SUCCESS);
}
