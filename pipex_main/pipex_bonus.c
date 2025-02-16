/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:20:32 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 08:49:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"
#include <stdlib.h>

void	init_pipe(t_pipe *pipe_x)
{
	pipe_x->cmds = NULL;
	pipe_x->paths = NULL;
	pipe_x->envp = NULL;
	pipe_x->pipe_fd[0] = -1;
	pipe_x->pipe_fd[1] = -1;
	pipe_x->exit_code = EXIT_SUCCESS;
	pipe_x->prev_pipe = -1;
	pipe_x->cmds_count = 0;
	pipe_x->infile_fd = -1;
	pipe_x->outfile_fd = -1;
	pipe_x->pid = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe_x;

	init_pipe(&pipe_x);
	if (!parser(&pipe_x, argc, argv, envp))
		return (EXIT_FAILURE);
	if (!executor(&pipe_x))
		return (EXIT_FAILURE);
	cleanup(&pipe_x, 3);
	return (pipe_x.exit_code);
}
