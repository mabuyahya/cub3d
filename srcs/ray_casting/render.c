#include "cub3d.h"

static void get_background_colors(t_game *game, int *floor_color, int *ceiling_color)
{
    *floor_color = 0xFF << 24 | 
		(game->scene->f_color_rgb[0] << 16) | 
		(game->scene->f_color_rgb[1] << 8) | 
		game->scene->f_color_rgb[2];
    *ceiling_color = 0xFF << 24 | 
		(game->scene->c_color_rgb[0] << 16) | 
		(game->scene->c_color_rgb[1] << 8) | 
		game->scene->c_color_rgb[2];
}

static void draw_background_pixels(t_game *game, int floor_color, int ceiling_color)
{
    int x;
    int y;

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
}

static void render_background(t_game *game)
{
    int floor_color;
    int ceiling_color;

    get_background_colors(game, &floor_color, &ceiling_color);
    draw_background_pixels(game, floor_color, ceiling_color);
}

static void render_walls(t_game *game)
{
    int x;
    int y;

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
}

void render_frame(t_game *game)
{
    render_background(game);
    render_walls(game);
}
