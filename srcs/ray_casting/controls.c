#include "cub3d.h"

// Movement speed and rotation speed constants
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

void move_forward(t_game *game)
{
    double new_x = game->player.position.x + game->player.direction.x * MOVE_SPEED;
    double new_y = game->player.position.y + game->player.direction.y * MOVE_SPEED;
    
    // Check collision with walls (allow movement only if the cell is '0' - empty space)
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void move_backward(t_game *game)
{
    double new_x = game->player.position.x - game->player.direction.x * MOVE_SPEED;
    double new_y = game->player.position.y - game->player.direction.y * MOVE_SPEED;
    
    // Check collision with walls (allow movement only if the cell is '0' - empty space)
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void move_left(t_game *game)
{
    double new_x = game->player.position.x + game->player.direction.y * MOVE_SPEED;
    double new_y = game->player.position.y - game->player.direction.x * MOVE_SPEED;
    
    // Check collision with walls (allow movement only if the cell is '0' - empty space)
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void move_right(t_game *game)
{
    double new_x = game->player.position.x - game->player.direction.y * MOVE_SPEED;
    double new_y = game->player.position.y + game->player.direction.x * MOVE_SPEED;
    
    // Check collision with walls (allow movement only if the cell is '0' - empty space)
    if (game->scene->map->map_2d[(int)new_y][(int)game->player.position.x] != '1')
        game->player.position.y = new_y;
    if (game->scene->map->map_2d[(int)game->player.position.y][(int)new_x] != '1')
        game->player.position.x = new_x;
}

void rotate_left(t_game *game)
{
    // Save old direction and plane
    double old_dir_x = game->player.direction.x;
    double old_plane_x = game->plane_vector.x;
    
    // Rotate direction vector
    game->player.direction.x = game->player.direction.x * cos(ROT_SPEED) - game->player.direction.y * sin(ROT_SPEED);
    game->player.direction.y = old_dir_x * sin(ROT_SPEED) + game->player.direction.y * cos(ROT_SPEED);
    
    // Rotate plane vector
    game->plane_vector.x = game->plane_vector.x * cos(ROT_SPEED) - game->plane_vector.y * sin(ROT_SPEED);
    game->plane_vector.y = old_plane_x * sin(ROT_SPEED) + game->plane_vector.y * cos(ROT_SPEED);
}

void rotate_right(t_game *game)
{
    // Save old direction and plane
    double old_dir_x = game->player.direction.x;
    double old_plane_x = game->plane_vector.x;
    
    // Rotate direction vector
    game->player.direction.x = game->player.direction.x * cos(-ROT_SPEED) - game->player.direction.y * sin(-ROT_SPEED);
    game->player.direction.y = old_dir_x * sin(-ROT_SPEED) + game->player.direction.y * cos(-ROT_SPEED);
    
    // Rotate plane vector
    game->plane_vector.x = game->plane_vector.x * cos(-ROT_SPEED) - game->plane_vector.y * sin(-ROT_SPEED);
    game->plane_vector.y = old_plane_x * sin(-ROT_SPEED) + game->plane_vector.y * cos(-ROT_SPEED);
}

void handle_keypress(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;
    
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
        {
            mlx_close_window(game->mlx.mlx_ptr);
        }
        else if (keydata.key == MLX_KEY_W)
        {
            move_forward(game);
        }
        else if (keydata.key == MLX_KEY_S)
        {
            move_backward(game);
        }
        else if (keydata.key == MLX_KEY_A)
        {
            move_left(game);
        }
        else if (keydata.key == MLX_KEY_D)
        {
            move_right(game);
        }
        else if (keydata.key == MLX_KEY_LEFT)
        {
            rotate_left(game);
        }
        else if (keydata.key == MLX_KEY_RIGHT)
        {
            rotate_right(game);
        }
    }
}

void handle_close(void *param)
{
    t_game *game = (t_game *)param;
    free_all_and_exit_terminate(game);
}
