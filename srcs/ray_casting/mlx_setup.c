#include "cub3d.h"



void	mlx_setup(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", true);
	if (!game->mlx.mlx_ptr)
	{
		ft_putendl_fd("Error: MLX initialization failed", 2);
		free_all_and_exit(game->scene);
	}
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.img_ptr)
	{
		ft_putendl_fd("Error: MLX image creation failed", 2);
		mlx_terminate(game->mlx.mlx_ptr);
		free_all_and_exit(game->scene);
	}
	game->mlx.img_data = (int *)game->mlx.img_ptr->pixels;
	game->mlx.width = WIN_WIDTH;
	game->mlx.height = WIN_HEIGHT;

	// Initialize textures and pixel map
	init_textures(game);
	init_pixel_map(game);

	// Set up event handlers
	mlx_key_hook(game->mlx.mlx_ptr, &handle_keypress, game);
	mlx_close_hook(game->mlx.mlx_ptr, &handle_close, game);
}
