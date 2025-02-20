#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
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
	char	**paths;
	char	**envp;

	int		pipe_fd[2];
	int		prev_pipe;

	int		cmds_count;

	int		infile_fd;
	int		outfile_fd;

	t_cmd	*cmds;
}			t_pipe;

#endif
