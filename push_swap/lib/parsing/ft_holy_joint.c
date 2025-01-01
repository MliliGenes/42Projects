/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_holy_joint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:53:46 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/01 17:09:12 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_holy_joint(char **argv)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		result = ft_strjoin(result, argv[i]);
		if (!result)
			return (NULL);
        if (argv[i + 1])
        {
            result = ft_strjoin(result, " ");
            if (!result)
                return (NULL);
        }
		i++;
	}
	return (result);
}
