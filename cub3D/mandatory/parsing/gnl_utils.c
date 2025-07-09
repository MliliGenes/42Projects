/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:53:59 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:21:18 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	allocation_manager(int fd, char **save)
{
	int		rd;
	char	*buffer;

	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			buffer = NULL;
			free(*save);
			*save = NULL;
			return ;
		}
		buffer[rd] = '\0';
		*save = ft_strcat(*save, buffer);
		if (!ft_newline_check(buffer))
			break ;
	}
	free(buffer);
}

int	ft_newline_check(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_cpy(char *string, char *string1, int n)
{
	int	i;

	i = 0;
	if (!string || !string1)
		return (NULL);
	while (string1[i] && i < n)
	{
		string[i] = string1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strcat(char *string1, char *string2)
{
	char	*ptr;

	if (!string1)
	{
		string1 = malloc(1);
		string1[0] = '\0';
	}
	if (!string2 || !string1)
	{
		free(string1);
		string1 = NULL;
		return (NULL);
	}
	ptr = malloc(ft_sstrlen(string1) + ft_sstrlen(string2) + 1);
	if (!ptr)
	{
		free(string1);
		string1 = NULL;
		return (NULL);
	}
	ft_cpy(ptr, string1, ft_sstrlen(string1));
	ft_cpy(ptr + ft_sstrlen(string1), string2, ft_sstrlen(string2));
	free(string1);
	string1 = NULL;
	return (ptr);
}

int	ft_sstrlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}
