/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:05:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/15 17:01:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

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
	return (false);
}
