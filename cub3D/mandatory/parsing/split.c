/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:21 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:23 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	ft_count(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_free(int i, char **arr)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
	return (NULL);
}

static char	**ft_copy(char **arr, const char *str, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		arr[i][j] = *(str - len);
		len--;
		j++;
	}
	arr[i][j] = '\0';
	return (arr);
}

static char	**ft_cho9(char const *str, char **arr, char c, int word)
{
	int	i;
	int	len;
	int	num;

	i = 0;
	num = 0;
	while (num < word)
	{
		len = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			len++;
			i++;
		}
		arr[num] = malloc(len + 1);
		if (!arr[num])
			return (ft_free(num, arr));
		ft_copy(arr, &str[i], num, len);
		num++;
	}
	arr[num] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count(s, c);
	arr = (char **)malloc((sizeof(char *)) * (word_count + 1));
	if (!arr)
		return (NULL);
	arr = ft_cho9(s, arr, c, word_count);
	if (!arr)
		return (NULL);
	return (arr);
}
