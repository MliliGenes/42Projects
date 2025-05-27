/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 05:24:36 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 09:55:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int	init_read(int fd, char *buffer, int *b_read, int *b_pos)
{
	*b_read = read(fd, buffer, 1000);
	*b_pos = 0;
	if (*b_read <= 0)
		return (0);
	return (1);
}

static int	read_line(int fd, char *buffer, char *line, int *indices)
{
	int	i;
	int	*b_pos;
	int	*b_read;

	i = indices[0];
	b_pos = &indices[1];
	b_read = &indices[2];
	while (1)
	{
		if (*b_pos >= *b_read)
		{
			if (!init_read(fd, buffer, b_read, b_pos))
				break ;
		}
		line[i++] = buffer[(*b_pos)++];
		if (buffer[*b_pos - 1] == '\n')
			return (i);
	}
	return (i);
}

static char	*process_line(char *line, int length)
{
	if (length == 0)
		return (NULL);
	line[length] = '\0';
	return (ft_strdup(line));
}

char	*get_line(int fd)
{
	static char	buffer[1000];
	char		line[70000];
	static int	indices[3];

	indices[0] = 0;
	if (fd < 0)
		return (NULL);
	indices[0] = read_line(fd, buffer, line, indices);
	return (process_line(line, indices[0]));
}
