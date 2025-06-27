#include "cub3d.h"

void parse_colors_rgb(t_scene *scene)
{
	char **temp;
	char **temp2;
	char *trimmed;

	temp = ft_split(scene->f_color, ',');
	if (!temp)
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	temp2 = ft_split(scene->c_color, ',');
	if (!temp2)
	{
		free_2d_array(temp);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	trimmed = ft_strtrim(temp[0], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->f_color_rgb[0] = ft_atoi(trimmed);
	free(trimmed);
	trimmed = ft_strtrim(temp[1], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->f_color_rgb[1] = ft_atoi(trimmed);
	free(trimmed);
	trimmed = ft_strtrim(temp[2], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->f_color_rgb[2] = ft_atoi(trimmed);
	free(trimmed);
	trimmed = ft_strtrim(temp2[0], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->c_color_rgb[0] = ft_atoi(trimmed);
	free(trimmed);
	trimmed = ft_strtrim(temp2[1], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->c_color_rgb[1] = ft_atoi(trimmed);
	free(trimmed);
	trimmed = ft_strtrim(temp2[2], " \t");
	if (!trimmed)
	{
		free_2d_array(temp);
		free_2d_array(temp2);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	scene->c_color_rgb[2] = ft_atoi(trimmed);
	free(trimmed);
	free_2d_array(temp);
	free_2d_array(temp2);
}

int parse_content(t_scene *scene)
{
	int i;
	char *line;
	if (!scene || !scene->file_2d)
		return (1);
	i = 0;
	while (scene->file_2d[i])
	{
		line = ft_strtrim(scene->file_2d[i], " \t");
		if (ft_strncmp(line, "F", 1) == 0 && scene->f_color == NULL)
		{
			scene->f_color = line;
		}
		else if (ft_strncmp(line, "C", 1) == 0 && scene->c_color == NULL)
		{
			scene->c_color = line;
		}
		else if (ft_strncmp(line, "NO", 2) == 0 && scene->north_image == NULL)
		{
			scene->north_image = line;
		}
		else if (ft_strncmp(line, "SO", 2) == 0 && scene->south_image == NULL)
		{
			scene->south_image = line;
		}
		else if (ft_strncmp(line, "WE", 2) == 0 && scene->west_image == NULL)
		{
			scene->west_image = line;
		}
		else if (ft_strncmp(line, "EA", 2) == 0 && scene->east_image == NULL)
		{
			scene->east_image = line;
		}
		else
		{
			if (ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
				|| ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "NO", 2) == 0
				|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
			{
				free(line);
				return (1);
			}
			else if (line[0] == '1' || line[0] == '0')
			{
				free(line);
				return (0);
			}
			else
			{
				free(line);
				return (1);
			}
		}
		i++;
	}
	return (1);
}
