
#include "cub3d.h"

void build_game(t_scene *scene)
{
	t_game game;
	game.scene = scene;
	game_setup(&game);
	// mlx_setup(&game);
	get_raycasting_info(&game);
	// mlx_loop(game.mlx.mlx_ptr);
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
