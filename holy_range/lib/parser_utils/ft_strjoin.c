/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:58:22 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:24:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strjoin(char *s1, char *s2)
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
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (free(s1), joined);
}
