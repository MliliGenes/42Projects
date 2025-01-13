/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:48:09 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 13:58:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

static int	validate_file_name(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (!(path[len - 1] == 'r' && path[len - 2] == 'e' && path[len - 3] == 'b'
			&& path[len - 4] == '.'))
		return (0);
	return (1);
}

int	file_to_fd(char *path)
{
	int	fd;

	if (!path || !*path || !validate_file_name(path))
		return (-1);
	fd = open(path, O_RDONLY);
	return (fd);
}
