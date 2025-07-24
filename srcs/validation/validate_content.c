/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:28:44 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:43:02 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	// f = ft_calloc(count_word(s, delims) + 1, sizeof(char *));

char	**terpo_split(const char *s, const char *delims)
{
	char	**f;
	int		i;
	int		j;
	int		start_word;

	if (!no_space(&i, &j, &start_word, &f, (char *)s))
		return (NULL);
	while ((size_t)i <= ft_strlen(s))
	{
		if (!is_delim(s[i], delims) && start_word < 0)
			start_word = i;
		else if ((is_delim(s[i], delims) || (size_t)i == ft_strlen(s))
			&& start_word >= 0)
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

static int	validate_image_element(char **element, t_scene *scene)
{
	char	**temp;
	int		i;

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
	return (0);
}

static int	validate_color_element(char **element, t_scene *scene)
{
	char	*color_part;
	int		i;

	i = 0;
	while ((*element)[i] && (*element)[i] != ' ' && (*element)[i] != '\t')
		i++;
	if ((*element)[i] == '\0' || i != 1)
		return (1);
	while ((*element)[i] && ((*element)[i] == ' ' || (*element)[i] == '\t'))
		i++;
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
	return (0);
}

int	validate_element(char **element, int is_image, t_scene *scene)
{
	if (is_image)
		return (validate_image_element(element, scene));
	else
		return (validate_color_element(element, scene));
}

int	validate_content(t_scene *scene)
{
	if (!scene->f_color || !scene->c_color || !scene->north_image
		|| !scene->south_image || !scene->west_image || !scene->east_image)
	{
		free_all_and_print_exit(scene, ERR_FILE_NOT_COMPLETED);
	}
	if (validate_element(&scene->f_color, 0, scene)
		|| validate_element(&scene->c_color, 0, scene)
		|| validate_element(&scene->north_image, 1, scene)
		|| validate_element(&scene->south_image, 1, scene)
		|| validate_element(&scene->west_image, 1, scene)
		|| validate_element(&scene->east_image, 1, scene))
	{
		return (1);
	}
	return (0);
}
