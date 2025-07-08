#include "cub3d.h"

t_point find_player_direction(char direction)
{
    t_point dir;
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
    return dir;
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
    game->player.direction = find_player_direction(game->scene->map->map_2d[(int)game->player.position.y][(int)game->player.position.x]);
    game->plane_vector.x = 0.66;
    game->plane_vector.y = 0;
}
