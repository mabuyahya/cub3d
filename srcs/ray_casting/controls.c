#include "cub3d.h"

// Movement speed and rotation speed constants

void move_forward(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.position.x + game->player.direction.x * MOVE_SPEED;
    new_y = game->player.position.y + game->player.direction.y * MOVE_SPEED;
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
    game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
    game->player.position.x = new_x;
}

void move_backward(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.position.x - game->player.direction.x * MOVE_SPEED;
    new_y = game->player.position.y - game->player.direction.y * MOVE_SPEED;
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void move_left(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.position.x + game->player.direction.y * MOVE_SPEED;
    new_y = game->player.position.y - game->player.direction.x * MOVE_SPEED;
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void move_right(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.position.x - game->player.direction.y * MOVE_SPEED;
    new_y = game->player.position.y + game->player.direction.x * MOVE_SPEED;
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void rotate_left(t_game *game)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player.direction.x;
    old_plane_x = game->plane_vector.x;
    game->player.direction.x = game->player.direction.x * cos(-ROT_SPEED) - game->player.direction.y * sin(-ROT_SPEED);
    game->player.direction.y = old_dir_x * sin(-ROT_SPEED) + game->player.direction.y * cos(-ROT_SPEED);
    game->plane_vector.x = game->plane_vector.x * cos(-ROT_SPEED) - game->plane_vector.y * sin(-ROT_SPEED);
    game->plane_vector.y = old_plane_x * sin(-ROT_SPEED) + game->plane_vector.y * cos(-ROT_SPEED);
}

void rotate_right(t_game *game)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player.direction.x;
    old_plane_x = game->plane_vector.x;
    game->player.direction.x = game->player.direction.x * cos(ROT_SPEED) - game->player.direction.y * sin(ROT_SPEED);
    game->player.direction.y = old_dir_x * sin(ROT_SPEED) + game->player.direction.y * cos(ROT_SPEED);
    game->plane_vector.x = game->plane_vector.x * cos(ROT_SPEED) - game->plane_vector.y * sin(ROT_SPEED);
    game->plane_vector.y = old_plane_x * sin(ROT_SPEED) + game->plane_vector.y * cos(ROT_SPEED);
}

void handle_escpress(void *param)
{
    t_game *game = (t_game *)param;
    free_all_and_exit_terminate(game);
}

void handle_close(void *param)
{
    t_game *game = (t_game *)param;
    free_all_and_exit_terminate(game);
}
