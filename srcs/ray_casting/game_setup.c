/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:02:56 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/23 18:03:56 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	find_player_direction(char direction)
{
	t_point	dir;

	dir.x = 0;
	dir.y = 0;
	if (direction == 'N')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (direction == 'S')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else if (direction == 'E')
	{
		dir.x = 1;
		dir.y = 0;
	}
	else if (direction == 'W')
	{
		dir.x = -1;
		dir.y = 0;
	}
	return (dir);
}

t_point	find_player_position(t_scene *scene)
{
	t_point	position;
	t_point	var;

	position = (t_point){-1, -1};
	var = (t_point){0, 0};
	while (scene->map->map_2d[(int)var.y])
	{
		var.x = 0;
		while (scene->map->map_2d[(int)var.y][(int)var.x])
		{
			if (scene->map->map_2d[(int)var.y][(int)var.x] == 'N'
				|| scene->map->map_2d[(int)var.y][(int)var.x] == 'S'
				|| scene->map->map_2d[(int)var.y][(int)var.x] == 'E'
				|| scene->map->map_2d[(int)var.y][(int)var.x] == 'W')
			{
				position.x = var.x + 0.5;
				position.y = var.y + 0.5;
				return (position);
			}
			var.x++;
		}
		var.y++;
	}
	return (position);
}

t_point	find_plane_direction(t_point direction)
{
	t_point	plane_vector;

	plane_vector.x = 0;
	plane_vector.y = 0;
	if (direction.x == 0 && direction.y == -1)
	{
		plane_vector.x = 0.66;
		plane_vector.y = 0;
	}
	else if (direction.x == 0 && direction.y == 1)
	{
		plane_vector.x = -0.66;
		plane_vector.y = 0;
	}
	else if (direction.x == 1 && direction.y == 0)
	{
		plane_vector.x = 0;
		plane_vector.y = 0.66;
	}
	else if (direction.x == -1 && direction.y == 0)
	{
		plane_vector.x = 0;
		plane_vector.y = -0.66;
	}
	return (plane_vector);
}

void	game_setup(t_game *game)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	game->player.position = find_player_position(game->scene);
	temp = (int)game->player.position.x;
	j = game->scene->map->map_2d[(int)game->player.position.y][temp];
	game->player.direction = find_player_direction(j);
	game->plane_vector = find_plane_direction(game->player.direction);
	while (i < NUM_TEXTURES)
	{
		game->texture_buffer[i] = NULL;
		i++;
	}
	game->pixels_map = NULL;
}
