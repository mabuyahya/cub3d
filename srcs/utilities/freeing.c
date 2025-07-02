#include "cub3d.h"

// we will but here the things that need to be freed so we won't forget to free anything
/*
scene->file
scene->file_2d
*/

void free_all(t_scene *scene)
{
	if (scene->file)
		free(scene->file);
	if (scene->file_2d)
		free_2d_array(scene->file_2d);
	if (scene->f_color)
		free(scene->f_color);
	if (scene->c_color)
		free(scene->c_color);
	if (scene->north_image)
		free(scene->north_image);
	if (scene->south_image)
		free(scene->south_image);
	if (scene->west_image)
		free(scene->west_image);
	if (scene->east_image)
		free(scene->east_image);
	if (scene->map)
	{
		if (scene->map->map_2d)
			free_2d_array(scene->map->map_2d);
		if (scene->map->map)
			free(scene->map->map);
		if (scene->map->map_lens)
		{
			free(scene->map->map_lens);
		}
		free(scene->map);
	}
}

void free_all_and_exit(t_scene *scene)
{
	free_all(scene);
	exit(EXIT_FAILURE);
}

void free_all_and_print_exit(t_scene *scene, int error_type)
{
	print_error_type(error_type);
	free_all(scene);
	exit(EXIT_FAILURE);
}

void free_2d_array(char **array)
{
	int i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void free_all_and_print_exit_terminate(t_game *game, int error_type)
{
	print_error_type(error_type);
	free_all(game->scene);
	mlx_terminate(game->mlx.mlx_ptr);
	exit(EXIT_FAILURE);
}

void free_all_and_exit_terminate(t_game *game)
{
	free_all(game->scene);
	mlx_terminate(game->mlx.mlx_ptr);
	exit(EXIT_FAILURE);
}