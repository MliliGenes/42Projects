/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:27:16 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/01 17:57:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_validate_args(char **num)
{
    while (*num)
    {
        if (*num == '+' || *num == '-')
            num++;
        if (!*num)
            return (0);
        while (*num && *num >= '0' && *num <= '9')
            num++;
        if (*num != '\0')
            return (0);
        num++;
    }
    return (1);
}
