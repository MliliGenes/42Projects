/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:11 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 18:05:31 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

t_map	*parse_colors_utils_norm(t_map *parse, t_utils *utils)
{
	int			i;
	long long	codex;
	long long	codexo;

	i = 0;
	while (i < 3)
	{
		codex = ft_atoi(utils->f[i]);
		codexo = ft_atoi(utils->c[i]);
		if (codexo == -1 || codex == -1 || codex > 255 || codexo > 255)
		{
			parsiixx_freex(parse);
			return (NULL);
		}
		parse->floor_color[i] = (unsigned int)codex;
		parse->ceiling_color[i] = (unsigned int)codexo;
		i++;
	}
	return (parse);
}

t_map	*ret_help(char **map)
{
	ft_freeing(map);
	return (NULL);
}

t_map	*ret_first_help(char *ptr, char **arr)
{
	free(ptr);
	ft_freeing(arr);
	printf("ERROR : invalid map =(\n");
	return (NULL);
}

char	*read_line_hh(int fd)
{
	char	*ptr;
	char	*tet1;
	char	*tet;

	ptr = NULL;
	tet1 = get_next_line(fd);
	if (tet1 == NULL)
	{
		close(fd);
		printf("Empty file :)\n");
		return (NULL);
	}
	while (tet1 != NULL)
	{
		tet = ft_strdup(tet1);
		free(tet1);
		ptr = ft_strcat(ptr, tet);
		free(tet);
		tet1 = get_next_line(fd);
	}
	close(fd);
	return (ptr);
}

char	*ft_copy_st(char *start, int len, int j, char *ptr)
{
	int	k;

	k = 0;
	while (len)
	{
		start[k] = ptr[j - len];
		len--;
		k++;
	}
	start[k] = '\0';
	return (start);
}
