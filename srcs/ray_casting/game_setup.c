#include "cub3d.h"

double find_player_angle(char direction)
{
    if (direction == 'N')
        return PI / 2; // 90 degrees
    else if (direction == 'S')
        return 3 * PI / 2; // 270 degrees
    else if (direction == 'E')
        return 0;
    else if (direction == 'W')
        return PI; // 180 degrees
    return -1;
}

t_point find_player_position(t_scene *scene)
{
    t_point position;
    int i, j;

    position.x = -1;
    position.y = -1;

    for (i = 0; scene->map->map_2d[i]; i++)
    {
        for (j = 0; scene->map->map_2d[i][j]; j++)
        {
            if (scene->map->map_2d[i][j] == 'N' || 
                scene->map->map_2d[i][j] == 'S' || 
                scene->map->map_2d[i][j] == 'E' || 
                scene->map->map_2d[i][j] == 'W')
            {
                position.x = j;
                position.y = i;
                return position;
            }
        }
    }
    return position;
}

void game_setup(t_game *game)
{
    game->player.position = find_player_position(game->scene);
    game->player.angle = find_player_angle(game->scene->map->map_2d[(int)game->player.position.y][(int)game->player.position.x]);
    game->fov = 60;
    game->mlx.width = 1000;
    game->mlx.height = 1000;
}
