#include "cub3d.h"

void get_plane(t_game *game)
{
    int i;
    double angle_per_ray;
    double current_angle;
    double base_angle;
    double fov_radians;

    i = 0;
    fov_radians = (game->fov * PI) / 180.0; // Convert FOV to radians
    angle_per_ray = fov_radians / RAYS_COUNT;
    base_angle = atan2(game->player.direction.y, game->player.direction.x);
    
    while (i < RAYS_COUNT)
    {
        current_angle = base_angle - (fov_radians / 2.0) + (i * angle_per_ray);
        
        // Calculate ray direction for this ray
        game->plane[i].x = cos(current_angle);
        game->plane[i].y = sin(current_angle);
        
        i++;
    }
}
