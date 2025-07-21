#include "cub3d.h"

static int	get_the_map(t_scene *scene, int i)
{
	char	*temp;
	char	*temp2;

	temp = ft_strdup("");
	if (!temp)
		return (1);
	while (scene->file_2d[i])
	{
		temp2 = ft_strjoin(temp, scene->file_2d[i]);
		if (!temp2)
		{
			free(temp);
			return (1);
		}
		free(temp);
		temp = ft_strjoin(temp2, "\n");
		if (!temp)
		{
			free(temp2);
			return (1);
		}
		free(temp2);
		i++;
	}
	scene->map->map = temp;
	return (0);
}

int	parse_map(t_scene *scene)
{
	int	i;

	i = 6;
	if (scene->file_2d[6])
	{
		if (get_the_map(scene, i))
			return (1);
	}
	scene->map->map_2d = ft_split(scene->map->map, '\n');
	if (!scene->map->map_2d)
		return (1);
	return (0);
}
