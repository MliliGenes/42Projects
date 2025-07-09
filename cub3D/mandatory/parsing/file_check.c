/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:53:50 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:18:45 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	ft_initialse_flags(t_norm *norm)
{
	norm->flags[0] = 0;
	norm->flags[1] = 0;
	norm->flags[2] = 0;
	norm->flags[3] = 0;
	norm->flags[4] = 0;
	norm->flags[5] = 0;
}

int	ft_norm_gg_codex(t_utils *utils, char **arr, t_norm *norm)
{
	if (arr[norm->i][norm->k] == 'F' && !norm->flags[4])
	{
		if (!break_lines(arr, norm, utils))
			return (-1);
		norm->flags[4] = 1;
	}
	else if (arr[norm->i][norm->k] == 'C' && !norm->flags[5])
	{
		if (!break_lines(arr, norm, utils))
			return (-1);
		norm->flags[5] = 1;
	}
	else
		return (-1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

int	ft_check_dot(char *path)
{
	char	*ber;
	char	*dot;
	int		i;

	ber = "cub";
	dot = ft_strrchr(path, '.');
	if (!dot)
		return (0);
	dot = dot + 1;
	if (ft_strlen(dot) != 3)
		return (0);
	i = 0;
	while (i < 3)
	{
		if (dot[i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}
