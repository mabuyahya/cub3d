#include "cub3d.h"

static int get_the_map(t_scene *scene, int i, char *temp2)
{
	char	*temp;

	while (scene->file_2d[i])
	{
		free(scene->map->map);
		scene->map->map = ft_strjoin(temp2, scene->file_2d[i]);
		if (!scene->map->map)
		{
			free(temp2);
			return (1);
		}
		free(temp2);
		temp = ft_strdup(scene->map->map);
		if (!temp)
			return (1);
		temp2 = ft_strjoin(temp, "\n");
		if (!temp2)
		{
			free(temp);
			return (1);
		}
		free(temp);
		i++;
	}
	free(temp2);
	return (0);
}

int parse_map(t_scene *scene)
{
	int i;
	char	*temp2;

	i = 6;
	temp2 = ft_strdup("");
	if (!temp2)
		return (1);	
	if (scene->file_2d[6])
	{
		if (get_the_map(scene, i, temp2))
			return (1);
	}
	scene->map->map_2d = ft_split(scene->map->map, '\n');
	if (!scene->map->map_2d)
		return (1);
	return (0);
}
