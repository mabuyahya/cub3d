#include "cub3d.h"

int validate_path(char *path, t_scene *scene)
{
	int	fd;
	(void)scene;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	close(fd);
	return (0);
}
