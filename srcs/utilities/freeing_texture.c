/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:31:30 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:31:34 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (game->texture_buffer[i])
		{
			free(game->texture_buffer[i]);
			game->texture_buffer[i] = NULL;
		}
		i++;
	}
}

void	free_pixel_map(t_game *game)
{
	int	i;

	if (!game->pixels_map)
		return ;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		if (game->pixels_map[i])
		{
			free(game->pixels_map[i]);
			game->pixels_map[i] = NULL;
		}
		i++;
	}
	free(game->pixels_map);
	game->pixels_map = NULL;
}

t_direction	get_direction(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}
