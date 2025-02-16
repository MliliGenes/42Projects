/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:42:43 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/15 17:01:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

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
