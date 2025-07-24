/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:20:30 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:20:35 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_pixel_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		ft_memset(game->pixels_map[y], 0, sizeof(int) * WIN_WIDTH);
		y++;
	}
}

void	setup_ray_params(t_game *game, int x, t_ray_vars *ray)
{
	double	camera_x;

	ray->x = x;
	camera_x = (2 * x / (double)WIN_WIDTH) - 1;
	ray->ray_dir_x = game->player.direction.x + game->plane_vector.x * camera_x;
	ray->ray_dir_y = game->player.direction.y + game->plane_vector.y * camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	setup_step_and_side_dist(t_game *game, t_ray_vars *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.position.x
				- (int)game->player.position.x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)game->player.position.x + 1.0
				- game->player.position.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.position.y
				- (int)game->player.position.y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)game->player.position.y + 1.0
				- game->player.position.y) * ray->delta_dist_y;
	}
}
