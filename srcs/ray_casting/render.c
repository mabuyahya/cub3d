#include "cub3d.h"

void	render_frame(t_game *game)
{
	int x;
	int y;
	int floor_color;
	int ceiling_color;

	// Convert RGB values to integer colors (RGBA format for MLX42)
	floor_color = (game->scene->f_color_rgb[0] << 24) | 
				  (game->scene->f_color_rgb[1] << 16) | 
				  (game->scene->f_color_rgb[2] << 8) | 0xFF;
	ceiling_color = (game->scene->c_color_rgb[0] << 24) | 
					(game->scene->c_color_rgb[1] << 16) | 
					(game->scene->c_color_rgb[2] << 8) | 0xFF;

	// Clear the image buffer first
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				game->mlx.img_data[y * WIN_WIDTH + x] = ceiling_color;
			else
				game->mlx.img_data[y * WIN_WIDTH + x] = floor_color;
			x++;
		}
		y++;
	}

	// Apply the pixel map to the image buffer
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (game->pixels_map[y][x] != 0)
				game->mlx.img_data[y * WIN_WIDTH + x] = game->pixels_map[y][x];
			x++;
		}
		y++;
	}

	// Display the image
	mlx_image_to_window(game->mlx.mlx_ptr, game->mlx.img_ptr, 0, 0);
}
