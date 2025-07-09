/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:08 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:51:22 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

int	find_map(char *ptr, int i)
{
	int	j;

	while (ptr[i] && (ptr[i] != '0' && ptr[i] != '1' && ptr[i] != 'N'
			&& ptr[i] != 'S' && ptr[i] != 'E' && ptr[i] != 'W'))
		i++;
	j = i;
	while (ptr[j] != '\n')
		j--;
	return (j + 1);
}

void	fttt_while_help(char **arr, int *size, int *i, int *k)
{
	*size = 0;
	while (arr[*size])
		(*size)++;
	*i = 0;
	while (*i < *size)
	{
		*k = 0;
		while (arr[*i][*k] == 32 || (arr[*i][*k] >= 9 && arr[*i][*k] <= 13))
			(*k)++;
		if (arr[*i][*k] == '1')
			break ;
		(*i)++;
	}
}

char	**ft_checking_nwl(char *ptr, char **arr)
{
	char	**ret;
	int		size;
	int		i;
	int		k;

	(void)ptr;
	fttt_while_help(arr, &size, &i, &k);
	size = i;
	while (arr[size])
		size++;
	size -= i;
	ret = malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	k = 0;
	while (k < size)
	{
		ret[k] = ft_strdup(arr[i + k]);
		k++;
	}
	ret[k] = NULL;
	return (ret);
}

int	ft_check_emptyline(char *ptr, int *i)
{
	while (ptr[*i] && ptr[*i] != '\n' && (ptr[*i] == 32 || (ptr[*i] >= 9
				&& ptr[*i] <= 13)))
		(*i)++;
	if (ptr[*i] == '\n')
		return (-1);
	return (1);
}

int	ft_valide_lines(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\n')
		{
			if (ptr[i + 1])
			{
				i++;
				if (ft_check_emptyline(ptr, &i) == -1)
					return (-1);
			}
		}
		i++;
	}
	return (1);
}
