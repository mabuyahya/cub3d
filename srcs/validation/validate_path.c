#include "cub3d.h"

int validate_path(char *path, t_scene *scene)
{
	int	fd;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free_all_and_print_exit(scene, ERR_IMAGE_NOT_FOUND);
	}
	close(fd);
	return (0);
}
