#include "cub3d.h"

t_point find_player_direction(char direction)
{
    t_point dir;
    
    // Initialize to default values
    dir.x = 0;
    dir.y = 0;
    
    if (direction == 'N')
    {
        dir.x = 0;
        dir.y = -1;  // Fixed: North should be negative Y
    }
    else if (direction == 'S')
    {
        dir.x = 0;
        dir.y = 1;   // Fixed: South should be positive Y
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
                position.x = j + 0.5;  // Center of the cell
                position.y = i + 0.5;  // Center of the cell
                return position;
            }
        }
    }
    return position;
}

t_point find_plane_direction(t_point direction)
{
    t_point plane_vector;
    
    // Initialize to default values
    plane_vector.x = 0;
    plane_vector.y = 0;

    if (direction.x == 0 && direction.y == -1) // North
    {
        plane_vector.x = 0.66;
        plane_vector.y = 0;
    }
    else if (direction.x == 0 && direction.y == 1) // South
    {
        plane_vector.x = -0.66;
        plane_vector.y = 0;
    }
    else if (direction.x == 1 && direction.y == 0) // East
    {
        plane_vector.x = 0;
        plane_vector.y = 0.66;
    }
    else if (direction.x == -1 && direction.y == 0) // West
    {
        plane_vector.x = 0;
        plane_vector.y = -0.66;
    }
    return plane_vector;
}

void game_setup(t_game *game)
{
    int i;

    i = 0;
    game->player.position = find_player_position(game->scene);
    game->player.direction = find_player_direction(game->scene->map->map_2d[(int)game->player.position.y][(int)game->player.position.x]);
    game->plane_vector = find_plane_direction(game->player.direction);
    game->fov = 60; // Set field of view in degrees
    
    while (i < NUM_TEXTURES)
    {
        game->texture_buffer[i] = NULL;
        i++;
    }
    game->pixels_map = NULL;
}
