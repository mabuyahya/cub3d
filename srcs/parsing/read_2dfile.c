
#include "cub3d.h"

void print_twodimensional_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
}

int read_2dfile(t_scene *scene)
{
	scene->file_2d = ft_split(scene->file, '\n');
	if (!scene->file_2d)
	{
		print_error_type(ERR_MEMORY_ALLOCATION);
		free(scene->file);
		return (1);
	}
	print_twodimensional_array(scene->file_2d);
	return (0);
}
