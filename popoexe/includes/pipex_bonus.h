/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:02:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/17 13:15:12 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*path;
	bool	valid;
}			t_cmd;

typedef struct s_pipe
{
	t_cmd	*cmds;
	char	**paths;
	char	**envp;
	int		pipe_fd[2];
	int		exit_code;
	int		prev_pipe;
	int		cmds_count;
	int		infile_fd;
	int		outfile_fd;
	bool	is_here_doc;
	pid_t	pid;
}			t_pipe;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strjoin(char *s1, char *s2, char sep);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strchr(const char *s, char c);
char		*ft_strjoin_(char *s1, char *s2);

void		*free_arr(char **arr, int last_index);
char		**ft_split(char const *s, char c);

int			handle_quotes(char *cmd, int *i, char *quote_type);
bool		two_quotes(char type, char *token);
bool		is_there_quote(char *token);
void		trim_quotes(char *token);
char		**tokenize_cmd(char *cmd);

bool		free_cmds_arr(t_cmd *cmds, int index);
bool		set_cmds_arr(t_pipe *pipe_x, char **cmds, int cmds_count);
bool		check_commands(t_pipe *pipe_x);

void		closing_io(int in, int out);
void		free_paths(char **paths);
bool		cleanup(t_pipe *pipe_x, int steps);

bool		parser(t_pipe *pipe_x, int argc, char **argv, char **envp);

void		redirect_io(t_pipe *pipe_x, int cmd_index);
void		execute_command(t_pipe *pipe_x, int cmd_index);
bool		executor(t_pipe *pipe_x);

bool		init_here_doc(char *limiter);
void		handle_here_doc(t_pipe *pipe_x, char *first, int *i,
				char **input_file);
char		*get_next_line(int fd);

#endif
