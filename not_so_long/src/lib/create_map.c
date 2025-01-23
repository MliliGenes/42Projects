/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:58:08 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/23 18:37:46 by sel-mlil         ###   ########.fr       */
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

t_list	*create_map(char *path)
{
	t_list	*head;
	t_list	*node;
	char	*line;
	int		fd;

	head = NULL;
	fd = file_to_fd(path);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = trim_new_line(line);
		if (!line || !*line)
			return (clear_t_list_list(head), NULL);
		node = create_t_list_node(line);
		if (!node)
			return (clear_t_list_list(head), NULL);
		add_back_t_list(&head, node);
		free(line);
	}
	return (close(fd), head);
}
