/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:00:04 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/23 17:01:14 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.direction.x;
	old_plane_x = game->plane_vector.x;
	game->player.direction.x = game->player.direction.x * cos(-ROT_SPEED)
		- game->player.direction.y * sin(-ROT_SPEED);
	game->player.direction.y = old_dir_x * sin(-ROT_SPEED)
		+ game->player.direction.y * cos(-ROT_SPEED);
	game->plane_vector.x = game->plane_vector.x * cos(-ROT_SPEED)
		- game->plane_vector.y * sin(-ROT_SPEED);
	game->plane_vector.y = old_plane_x * sin(-ROT_SPEED) + game->plane_vector.y
		* cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.direction.x;
	old_plane_x = game->plane_vector.x;
	game->player.direction.x = game->player.direction.x * cos(ROT_SPEED)
		- game->player.direction.y * sin(ROT_SPEED);
	game->player.direction.y = old_dir_x * sin(ROT_SPEED)
		+ game->player.direction.y * cos(ROT_SPEED);
	game->plane_vector.x = game->plane_vector.x * cos(ROT_SPEED)
		- game->plane_vector.y * sin(ROT_SPEED);
	game->plane_vector.y = old_plane_x * sin(ROT_SPEED) + game->plane_vector.y
		* cos(ROT_SPEED);
}

void	handle_escpress(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_all_and_exit_terminate(game);
}

void	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_all_and_exit_terminate(game);
}
