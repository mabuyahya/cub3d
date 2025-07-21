#include "cub3d.h"

void	render_frame(t_game *game)
{
	int x;
	int y;
	int floor_color;
	int ceiling_color;
	// MLX42 expects BGRA on Linux
	floor_color = (game->scene->f_color_rgb[0] << 24) |
              (game->scene->f_color_rgb[1] << 16) |
              (game->scene->f_color_rgb[2] << 8)  | 0xFF;

	ceiling_color = (game->scene->c_color_rgb[0] << 24) |
                (game->scene->c_color_rgb[1] << 16) |
                (game->scene->c_color_rgb[2] << 8)  | 0xFF;

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
	mlx_image_to_window(game->mlx.mlx_ptr, game->mlx.img_ptr, 0, 0);
}
