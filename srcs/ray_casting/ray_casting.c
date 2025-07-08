#include "cub3d.h"

void    ray_casting(t_game *game)
{
    int i;
    double ray_dir_x;
    double ray_dir_y;
    double camera_x;

    double delta_dist_x;
    double delta_dist_y;

    int step_x;
    int step_y;
    double side_dist_x;
    double side_dist_y;

    int map_x;
    int map_y;
    int side;
    map_x = (int)game->player.position.x;
    map_y = (int)game->player.position.y;

    double wall_dist;
    int line_height;
    int draw_start;
    int draw_end;
    int wall_x;
    i = 0;
    while (i < 5)
    {
        camera_x = (2 * i / (double)WIN_WIDTH) - 1; 
        ray_dir_x = game->player.direction.x + game->plane_vector.x * camera_x;
        ray_dir_y = game->player.direction.y + game->plane_vector.y * camera_x;

        delta_dist_x = fabs(1 / ray_dir_x);
        delta_dist_y = fabs(1 / ray_dir_y);

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->player.position.x - (int)game->player.position.x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = ((int)game->player.position.x + 1.0 - game->player.position.x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (game->player.position.y - (int)game->player.position.y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = ((int)game->player.position.y + 1.0 - game->player.position.y) * delta_dist_y;
        }

        while (1)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0; 
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->scene->map->map_2d[map_y][map_x] == '1')
                break;
        }

        if (side == 0)
            wall_dist = (map_x - game->player.position.x + (1 - step_x) / 2) / ray_dir_x;
        else
            wall_dist = (map_y - game->player.position.y + (1 - step_y) / 2) / ray_dir_y;
        line_height = (int)(WIN_HEIGHT / wall_dist);
        draw_start = -line_height / 2 + WIN_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + WIN_HEIGHT / 2;
        if (draw_end >= WIN_HEIGHT)
            draw_end = WIN_HEIGHT - 1;
        if (side == 1)
            wall_x = (int)(game->player.position.x + wall_dist * ray_dir_x);
        else
            wall_x = (int)(game->player.position.y + wall_dist * ray_dir_y);
        wall_x -= floor(wall_x); 
        i++;
    }
}
