/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:01:56 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/23 17:06:00 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x + game->player.direction.x * MOVE_SPEED;
	new_y = game->player.position.y + game->player.direction.y * MOVE_SPEED;
	if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x]
		!= '1')
		game->player.position.y = new_y;
	if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x]
		!= '1')
		game->player.position.x = new_x;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x - game->player.direction.x * MOVE_SPEED;
	new_y = game->player.position.y - game->player.direction.y * MOVE_SPEED;
	if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x]
		!= '1')
		game->player.position.y = new_y;
	if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x]
		!= '1')
		game->player.position.x = new_x;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x + game->player.direction.y * MOVE_SPEED;
	new_y = game->player.position.y - game->player.direction.x * MOVE_SPEED;
	if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x]
		!= '1')
		game->player.position.y = new_y;
	if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x]
		!= '1')
		game->player.position.x = new_x;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x - game->player.direction.y * MOVE_SPEED;
	new_y = game->player.position.y + game->player.direction.x * MOVE_SPEED;
	if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x]
		!= '1')
		game->player.position.y = new_y;
	if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x]
		!= '1')
		game->player.position.x = new_x;
}
