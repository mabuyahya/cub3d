
#include "cub3d.h"

void init_struct_with_nulls( t_scene *scene)
{
	scene->file = NULL;
	scene->file_2d = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->north_image = NULL;
	scene->south_image = NULL;
	scene->west_image = NULL;
	scene->east_image = NULL;
	scene->map = NULL;
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
	if (read_2dfile(scene))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int main(int argc, char **argv)
{
	t_scene scene;

	vname_and_vextension(argc, argv[1]);
	init_scene(argv[1],&scene);
	free(scene.file);
	return (0);
}

