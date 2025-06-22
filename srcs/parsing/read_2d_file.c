
#include "cub3d.h"

int read_2d_file(t_scene *scene)
{
	scene->file_2d = ft_split(scene->file, '\n');
	if (!scene->file_2d)
	{
		print_error_type(ERR_MEMORY_ALLOCATION);
		free(scene->file);
		return (1);
	}
	print_2d_array(scene->file_2d);
	return (0);
}
