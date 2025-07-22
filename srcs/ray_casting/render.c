#include "cub3d.h"

int make_argb_color(int r, int g, int b, int a)
{
	    return (a << 24) | (r << 16) | (g << 8) | b;
}

void	render_frame(t_game *game)
{
	int x;
	int y;
	int floor_color;
	int ceiling_color;

	floor_color = make_argb_color(
		game->scene->f_color_rgb[0],
		game->scene->f_color_rgb[1],
		game->scene->f_color_rgb[2],
		0xFF);
	ceiling_color = make_argb_color(
		game->scene->c_color_rgb[0],
		game->scene->c_color_rgb[1],
		game->scene->c_color_rgb[2],
		0xFF);
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
