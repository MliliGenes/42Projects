/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expended_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:24:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 12:24:38 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	free_expanded_map(char **expanded, int exp_height)
{
	int	i;

	if (!expanded)
		return ;
	i = 0;
	while (i < exp_height)
	{
		free(expanded[i]);
		i++;
	}
	free(expanded);
}
