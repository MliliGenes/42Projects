/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:58:08 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 01:33:19 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

list_t	*create_map(char *path)
{
	list_t	*head;
	list_t	*node;
	char	*line;
	int		fd;

	fd = file_to_fd(path);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
        if (!line)
            break;
		if (line)
		{
			// free the allocated shit
			return (NULL);
		}
		node = create_list_t_node(line);
		if (node)
		{
			// free the allocated shit
			return (NULL);
		}
		add_back_list_t(head, node);
	}
	return (head);
}
