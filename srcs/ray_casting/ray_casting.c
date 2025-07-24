/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:21:48 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:21:49 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	perform_dda(t_game *game, t_ray_vars *ray)
{
	ray->map_x = (int)game->player.position.x;
	ray->map_y = (int)game->player.position.y;
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->scene->map->map_2d[ray->map_y][ray->map_x] == '1')
			break ;
	}
	return (ray->side);
}

static void	calculate_wall_dimensions(t_ray_vars *ray,
		t_wall_texture_vars *wall_vars)
{
	wall_vars->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	wall_vars->draw_start = -wall_vars->line_height / 2 + WIN_HEIGHT / 2;
	if (wall_vars->draw_start < 0)
		wall_vars->draw_start = 0;
	wall_vars->draw_end = wall_vars->line_height / 2 + WIN_HEIGHT / 2;
	if (wall_vars->draw_end >= WIN_HEIGHT)
		wall_vars->draw_end = WIN_HEIGHT - 1;
}

static void	calculate_texture_params(t_game *game, t_ray_vars *ray,
		t_wall_texture_vars *wall_vars)
{
	if (ray->side == 0)
		wall_vars->wall_x = game->player.position.y + ray->wall_dist
			* ray->ray_dir_y;
	else
		wall_vars->wall_x = game->player.position.x + ray->wall_dist
			* ray->ray_dir_x;
	wall_vars->wall_x -= floor(wall_vars->wall_x);
	wall_vars->dir = get_direction(ray->side, ray->ray_dir_x, ray->ray_dir_y);
	wall_vars->tex_x = (int)(wall_vars->wall_x * TEXTURE_SIZE);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		wall_vars->tex_x = TEXTURE_SIZE - wall_vars->tex_x - 1;
}

static void	render_wall_texture(t_game *game, t_ray_vars *ray)
{
	t_wall_texture_vars	wall_vars;
	int					tex_y;

	calculate_wall_dimensions(ray, &wall_vars);
	calculate_texture_params(game, ray, &wall_vars);
	wall_vars.step = 1.0 * TEXTURE_SIZE / wall_vars.line_height;
	wall_vars.pos = (wall_vars.draw_start - WIN_HEIGHT / 2
			+ wall_vars.line_height / 2) * wall_vars.step;
	wall_vars.y = wall_vars.draw_start;
	while (wall_vars.y < wall_vars.draw_end)
	{
		tex_y = (int)wall_vars.pos & (TEXTURE_SIZE - 1);
		wall_vars.pos += wall_vars.step;
		wall_vars.color = game->texture_buffer[wall_vars.dir][TEXTURE_SIZE
			* tex_y + wall_vars.tex_x];
		game->pixels_map[wall_vars.y][ray->x] = wall_vars.color;
		wall_vars.y++;
	}
}

void	ray_casting(t_game *game)
{
	t_ray_vars	ray;
	int			x;

	clear_pixel_map(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		setup_ray_params(game, x, &ray);
		setup_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		if (ray.side == 0)
			ray.wall_dist = (ray.map_x - game->player.position.x + (1
						- ray.step_x) / 2) / ray.ray_dir_x;
		else
			ray.wall_dist = (ray.map_y - game->player.position.y + (1
						- ray.step_y) / 2) / ray.ray_dir_y;
		render_wall_texture(game, &ray);
		x++;
	}
}
