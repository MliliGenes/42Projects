/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:51:42 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 18:51:43 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

static char	*here(char *string)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	ft_cpy(ptr, string, i);
	return (ptr);
}

static char	*new_l(char *string)
{
	int		i;
	char	*ptr;
	int		size;

	i = 0;
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	while (*(string + i) && *(string + i) != '\n')
		i++;
	if (*(string + i) == '\n')
		i++;
	size = ft_sstrlen(string);
	ptr = malloc(size - i + 1);
	if (!ptr)
		return (NULL);
	ft_cpy(ptr, string + i, size);
	free(string);
	string = NULL;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	allocation_manager(fd, &string);
	if (!string)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	if (*string == '\0')
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	line = here(string);
	string = new_l(string);
	return (line);
}
