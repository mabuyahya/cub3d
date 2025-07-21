
#include "cub3d.h"
#include <unistd.h>

void game_loop(void *param)
{
	t_game *game = (t_game *)param;
	
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		handle_escpress(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx.mlx_ptr, MLX_KEY_RIGHT))
		rotate_right(game);
	
	ray_casting(game);
	render_frame(game);
	usleep(1000);
}

void build_game(t_scene *scene)
{
	t_game game;
	game.scene = scene;
	game_setup(&game);
	mlx_setup(&game);
	ray_casting(&game);
	mlx_loop_hook(game.mlx.mlx_ptr, &game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
	free_all_and_exit_terminate(&game);
}


int main(int argc, char **argv)
{
	t_scene scene;
	vname_and_vextension(argc, argv[1]);
	init_scene(argv[1],&scene);
	build_game(&scene);
	return (0);
}
