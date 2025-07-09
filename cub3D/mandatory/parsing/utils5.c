/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:30 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	**ft_cheking_fc(char **arr, int i, int k)
{
	char	**vv;
	t_help	help;
	char	*ptr;

	help.save = k;
	help.len = k;
	if (sil_count(arr, k, i) == -1)
		return (NULL);
	skiiipox(arr, &help, i);
	help.gg = help.save;
	lenght_sk(&help, arr, i);
	ptr = malloc((help.to_malc) + 1);
	help.len = help.gg;
	ptr = cpy_help_norm(arr, &help, i, ptr);
	vv = ft_split(ptr, ',');
	free(ptr);
	return (vv);
}

void	*ft_void_free(t_utils *utils)
{
	if (utils->no)
		ft_freeing(utils->no);
	if (utils->so)
		ft_freeing(utils->so);
	if (utils->we)
		ft_freeing(utils->we);
	if (utils->ea)
		ft_freeing(utils->ea);
	if (utils->c)
		ft_freeing(utils->c);
	if (utils->f)
		ft_freeing(utils->f);
	free(utils);
	return (NULL);
}

t_utils	*utils_ret(char *coor[4], t_norm *norm, char **arr)
{
	t_utils	*utils;

	coor[0] = "NO";
	coor[1] = "SO";
	coor[2] = "WE";
	coor[3] = "EA";
	utils = malloc(sizeof(t_utils));
	utils->no = NULL;
	utils->so = NULL;
	utils->ea = NULL;
	utils->we = NULL;
	utils->f = NULL;
	utils->c = NULL;
	norm->flag = 0;
	norm->size = 0;
	norm->i = 0;
	while (arr[norm->size])
		norm->size++;
	return (utils);
}

int	ft_nsea(char *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		if (map[i] == 'S' || map[i] == 'W' || map[i] == 'E' || map[i] == 'N')
			flag++;
		i++;
	}
	if (flag != 1)
		return (-1);
	return (1);
}

int	index_map_p(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == 32 || (map[i] >= 9 && map[i] <= 13))
				i++;
			if (map[i] == '1')
				return (i);
		}
		i++;
	}
	return (-1);
}
