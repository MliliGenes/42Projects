/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:58:08 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 06:59:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include <complex.h>
#include <stdlib.h>

static char	*trim_new_line(char *line)
{
	char	*trimmed;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	trimmed = malloc(i + 1);
	if (!trimmed)
		return (NULL);
	trimmed[i] = '\0';
	while (i-- > 0)
		trimmed[i] = line[i];
	free(line);
	return (trimmed);
}

list_t	*create_map(char *path)
{
	list_t	*head;
	list_t	*node;
	char	*line;
	int		fd;

	head = NULL;
	node = NULL;
	line = NULL;
	fd = file_to_fd(path);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = trim_new_line(line);
		if (!*line)
			return (clear_list_t_list(head), NULL);
		node = create_list_t_node(line);
		if (!node)
			return (clear_list_t_list(head), NULL);
		add_back_list_t(&head, node);
	}
	return (head);
}
