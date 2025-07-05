#include "cub3d.h"

void game_loop(void *param)
{
	(void)param;
}

void	mlx_setup(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init(610, 610, "Cub3D", true);
	if (!game->mlx.mlx_ptr)
	{
		ft_putendl_fd("Error: MLX initialization failed", 2);
		free_all_and_exit(game->scene);
	}
	mlx_loop_hook(game->mlx.mlx_ptr, &game_loop, NULL);
	mlx_loop(game->mlx.mlx_ptr);
}
