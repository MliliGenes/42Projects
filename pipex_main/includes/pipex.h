/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:02:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 00:02:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/_types/_pid_t.h>
# include <sys/fcntl.h>
# include <unistd.h>

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
	pid_t	pid;
}			t_pipe;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strjoin(char *s1, char *s2, char sep);
char		*ft_substr(char const *s, unsigned int start, size_t len);

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

#endif
