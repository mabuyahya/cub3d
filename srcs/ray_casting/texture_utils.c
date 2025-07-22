#include "cub3d.h"

void	init_textures(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->texture_buffer[i] = malloc(sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
		if (!game->texture_buffer[i])
		{
			free_textures(game);
			free_all_and_print_exit_terminate(game, ERR_MEMORY_ALLOCATION);
		}
		i++;
	}
	load_texture_to_buffer(game, game->scene->north_image, NORTH);
	load_texture_to_buffer(game, game->scene->south_image, SOUTH);
	load_texture_to_buffer(game, game->scene->west_image, WEST);
	load_texture_to_buffer(game, game->scene->east_image, EAST);
}

void	load_texture_to_buffer(t_game *game, char *path, int texture_index)
{
	mlx_texture_t	*texture;
	int				x;
	int				y;
	int				pixel_index;
	uint8_t			*pixel_data;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free_textures(game);
		free_all_and_print_exit_terminate(game, ERR_IMAGE_NOT_FOUND);
	}
	y = 0;
	while (y < TEXTURE_SIZE && y < (int)texture->height)
	{
		x = 0;
		while (x < TEXTURE_SIZE && x < (int)texture->width)
		{
			pixel_index = y * TEXTURE_SIZE + x;
			pixel_data = &texture->pixels[(y * texture->width + x) * 4];
			game->texture_buffer[texture_index][pixel_index] =
				(pixel_data[3] << 24) |
				(pixel_data[2] << 16) | 
				(pixel_data[1] << 8) |
				(pixel_data[0]);
				x++;
		}
		y++;
	}
	mlx_delete_texture(texture);
}

void	init_pixel_map(t_game *game)
{
	int i;

	game->pixels_map = malloc(sizeof(int *) * WIN_HEIGHT);
	if (!game->pixels_map)
		free_all_and_print_exit_terminate(game, ERR_MEMORY_ALLOCATION);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		game->pixels_map[i] = malloc(sizeof(int) * WIN_WIDTH);
		if (!game->pixels_map[i])
		{
			free_pixel_map(game);
			free_all_and_print_exit_terminate(game, ERR_MEMORY_ALLOCATION);
		}
		memset(game->pixels_map[i], 0, sizeof(int) * WIN_WIDTH);
		i++;
	}
}

void	free_textures(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (game->texture_buffer[i])
		{
			free(game->texture_buffer[i]);
			game->texture_buffer[i] = NULL;
		}
		i++;
	}
}

void	free_pixel_map(t_game *game)
{
	int i;

	if (!game->pixels_map)
		return;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		if (game->pixels_map[i])
		{
			free(game->pixels_map[i]);
			game->pixels_map[i] = NULL;
		}
		i++;
	}
	free(game->pixels_map);
	game->pixels_map = NULL;
}

t_direction	get_direction(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}
