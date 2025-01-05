/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:08:24 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:24:22 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validate(char *joined_argv)
{
	while (*joined_argv)
	{
		if (!(*joined_argv == ' ' || *joined_argv == '+' || *joined_argv == '-'
				|| (*joined_argv >= '0' && *joined_argv <= '9')))
			return (0);
		joined_argv++;
	}
	return (1);
}
