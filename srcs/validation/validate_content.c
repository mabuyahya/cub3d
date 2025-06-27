
#include "cub3d.h"

// this function for validating the content of the scene exept map



char	**terpo_split(const char *s, const char *delims)
{
	char	**f;
	int		i, j, start_word;

	no_space(&i, &j, &start_word);
	f = ft_calloc(count_word(s, delims) + 1, sizeof(char *));
	if (!f)
		return (NULL);
	while ((size_t)i <= ft_strlen(s))
	{
		if (!is_delim(s[i], delims) && start_word < 0)
			start_word = i;
		else if ((is_delim(s[i], delims) || (size_t)i == ft_strlen(s)) && start_word >= 0)
		{
			f[j] = fill_the_word(s, start_word, i);
			if (!f[j])
				return (free_all_split(f, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	f[j] = NULL;
	return (f);
}

int validate_element(char **element, int is_image, t_scene *scene)
{
	char	**temp;
	char	*color_part;
	int		i;

	if (is_image)
	{
		temp = terpo_split(*element, " \t");
		if (!temp)
			free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
		i = 0;
		while (temp[i])
			i++;
		if (i != 2)
		{
			free_2d_array(temp);
			return (1);
		}
		if (validate_path(temp[1], scene) || ft_strlen(temp[0]) != 2)
		{
			free_2d_array(temp);
			free_all_and_print_exit(scene, ERR_IMAGE_NOT_FOUND);
		}
		free(*element);
		*element = ft_strdup(temp[1]);
		free_2d_array(temp);
	}
	else
	{
		// For colors, we need to handle spaces within the RGB values
		// Find the first space after the identifier (F or C)
		i = 0;
		while ((*element)[i] && (*element)[i] != ' ' && (*element)[i] != '\t')
			i++;
		if ((*element)[i] == '\0' || i != 1)
			return (1);
		
		// Skip whitespace
		while ((*element)[i] && ((*element)[i] == ' ' || (*element)[i] == '\t'))
			i++;
		
		// Get the color part (everything after the identifier and spaces)
		color_part = ft_strdup(&(*element)[i]);
		if (!color_part)
			free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
		
		if (validate_color(color_part))
		{
			free(color_part);
			free_all_and_print_exit(scene, ERR_INVALID_COLOR);
		}
		
		free(*element);
		*element = color_part;
	}
	return (0);
}


int	validate_content(t_scene *scene)
{
	if (!scene->f_color || !scene->c_color
		|| !scene->north_image || !scene->south_image
		|| !scene->west_image || !scene->east_image)
	{
		free_all_and_print_exit(scene, ERR_FILE_NOT_COMPLETED);
	}
	if (validate_element(&scene->f_color, 0, scene) ||
		validate_element(&scene->c_color, 0, scene) ||
		validate_element(&scene->north_image, 1, scene) ||
		validate_element(&scene->south_image, 1, scene) ||
		validate_element(&scene->west_image, 1, scene) ||
		validate_element(&scene->east_image, 1, scene))
	{
		return (1);
	}
	return (0);

}
