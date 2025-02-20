/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:23:39 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/20 00:28:41 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	int		ii;

	if (!big)
		return (NULL);
	i = 0;
	while (big[i])
	{
		ii = 0;
		while (little[ii] && big[i + ii] == little[ii])
			ii++;
		if (!little[ii])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, char sep)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_strdup(""));
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!ptr)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[i])
		ptr[j++] = s1[i++];
	ptr[j++] = sep;
	i = 0;
	while (s2 && s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
