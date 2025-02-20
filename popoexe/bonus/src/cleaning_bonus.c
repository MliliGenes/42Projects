/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:05:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/17 13:20:26 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"
#include <unistd.h>

void	closing_io(int in, int out)
{
	close(in);
	close(out);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		i++;
	free_arr(paths, i);
}

bool	cleanup(t_pipe *pipe_x, int steps)
{
	if (steps >= 1)
		closing_io(pipe_x->infile_fd, pipe_x->outfile_fd);
	if (steps >= 2)
		free_paths(pipe_x->paths);
	if (steps >= 3)
		free_cmds_arr(pipe_x->cmds, pipe_x->cmds_count);
	if (pipe_x->is_here_doc)
		unlink("/tmp/here_doc");
	return (false);
}
