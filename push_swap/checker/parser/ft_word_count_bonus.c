/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:59:00 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 10:11:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	ft_word_count(char *s, char sep)
{
	int	i;
	int	in_word;
	int	cp;

	i = 0;
	in_word = 0;
	cp = 0;
	while (s[i])
	{
		if (s[i] == sep)
			in_word = 0;
		else if (s[i] != sep && in_word == 0)
		{
			in_word = 1;
			cp++;
		}
		i++;
	}
	return (cp);
}
