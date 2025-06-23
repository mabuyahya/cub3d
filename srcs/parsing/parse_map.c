#include "cub3d.h"

int parse_map(t_scene *scene)
{
	int i;
	char *temp;
	char *temp2;

	i = 0;
	// temp = ft_strdup("");
	temp2 = ft_strdup("");
	if (scene->file_2d[6])
	{
		i = 6;
		while (scene->file_2d[i])
		{
			free(scene->map->map);
			scene->map->map = ft_strjoin(temp2, scene->file_2d[i]);
			free(temp2);
			temp = ft_strdup(scene->map->map);
			temp2 = ft_strjoin(temp, "\n");
			free(temp);
			i++;
		}
	}
	free(temp2);
	scene->map->map_2d = ft_split(scene->map->map, '\n');
	return (0);
}
