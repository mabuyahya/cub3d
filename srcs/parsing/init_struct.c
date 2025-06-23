#include "cub3d.h"

static void init_struct_with_nulls( t_scene *scene)
{
	scene->file = NULL;
	scene->file_2d = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->north_image = NULL;
	scene->south_image = NULL;
	scene->west_image = NULL;
	scene->east_image = NULL;
	scene->map = malloc(sizeof(t_map));
	scene->map->map_2d = NULL;
	scene->map->map = NULL;
}

void init_scene(char *filename, t_scene *scene)
{
	int fd;

	init_struct_with_nulls(scene);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_type_exit(ERR_FILE_NOT_FOUND);
	if (read_file(fd, scene))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (read_2d_file(scene))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (parse_content(scene))
	{
		close(fd);
		free_all_and_print_exit(scene, ERR_UNNKNOWN_CHARACTER);
	}
	// printf("file content\n");
	// printf("scene->f_color %s\n", scene->f_color);
	// printf("scene->c_color %s\n", scene->c_color);
	// printf("scene->north_image %s\n", scene->north_image);
	// printf("scene->south_image %s\n", scene->south_image);
	// printf("scene->west_image %s\n", scene->west_image);
	// printf("scene->east_image %s\n", scene->east_image);
	parse_map(scene);

	close(fd);
}
