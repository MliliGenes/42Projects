/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:33 by sahamzao          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	sil_count(char **arr, int k, int i)
{
	int	sil;

	sil = 0;
	while (arr[i][k])
	{
		if (arr[i][k] == ',')
			sil++;
		k++;
	}
	if (sil != 2)
		return (-1);
	return (1);
}

void	skiiipox(char **arr, t_help *help, int i)
{
	while (arr[i][help->save] && (arr[i][help->save] == 32
			|| (arr[i][help->save] >= 9 && arr[i][help->save] <= 13)))
		(help->save)++;
}

void	lenght_sk(t_help *help, char **arr, int i)
{
	help->to_malc = 0;
	while (arr[i][help->save])
	{
		if (arr[i][help->save] != ' ' && (arr[i][help->save] < 9
				|| arr[i][help->save] > 13))
			help->to_malc++;
		help->save++;
	}
}

char	*cpy_help_norm(char **arr, t_help *help, int i, char *ptr)
{
	int	k;

	k = 0;
	while (k < help->to_malc)
	{
		if (arr[i][k + help->len] != ' ' && (arr[i][help->len + k] < 9
				|| arr[i][help->len + k] > 13))
		{
			ptr[k] = arr[i][help->len + k];
			k++;
		}
		else
			help->len++;
	}
	ptr[k] = '\0';
	return (ptr);
}
