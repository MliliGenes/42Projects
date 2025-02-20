/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:24:16 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/16 07:02:43 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*ft_strjoin_(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s1 && !s2)
		return (ft_strdup(""));
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (free(s1), s1 = NULL, joined);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
