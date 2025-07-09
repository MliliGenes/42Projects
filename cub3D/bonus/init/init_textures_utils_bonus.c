/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:07:34 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:49:50 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init_bonus.h"

void	*free_texture_array(uint32_t **arr, size_t height)
{
	size_t	k;

	if (!arr)
		return (NULL);
	k = 0;
	while (k < height)
		free(arr[k++]);
	free(arr);
	return (NULL);
}

uint32_t	**alloc_textures(mlx_texture_t *texture, t_texture *texture_data)
{
	size_t		h;
	size_t		w;
	uint32_t	**arr;
	size_t		j;

	if (!texture || !texture_data)
		return (NULL);
	texture_data->height = texture->height;
	texture_data->width = texture->width;
	h = texture->height;
	w = texture->width;
	arr = malloc((h + 1) * sizeof(uint32_t *));
	if (!arr)
		return (NULL);
	arr[h] = NULL;
	j = 0;
	while (j < h)
	{
		arr[j] = malloc(w * sizeof(uint32_t));
		if (!arr[j])
			return (free_texture_array(arr, j));
		j++;
	}
	return (arr);
}
