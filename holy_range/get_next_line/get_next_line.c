/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:02:17 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:37:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

char	*get_next(char *stash)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	i++;
	next = malloc(ft_strlen(stash) - i + 1);
	if (!next)
		return (free(stash), stash = NULL, NULL);
	j = 0;
	while (stash[i])
		next[j++] = stash[i++];
	next[j] = '\0';
	return (free(stash), stash = NULL, next);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_chunk(char *stash, int fd)
{
	int		read_bytes;
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(tmp), tmp = NULL, free(stash), stash = NULL, NULL);
		tmp[read_bytes] = '\0';
		stash = ft_strjoin(stash, tmp);
		if (!stash)
			return (free(tmp), tmp = NULL, NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (free(tmp), tmp = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	stash = get_chunk(stash, fd);
	if (!stash)
		return (free(stash), stash = NULL, NULL);
	line = ft_get_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = get_next(stash);
	return (line);
}
