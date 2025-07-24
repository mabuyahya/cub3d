/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:02:04 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:12:17 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_single_color_component(char *color_str, int *rgb_value,
									t_scene *scene, char **arrays[2])
{
	char	*trimmed;

	trimmed = ft_strtrim(color_str, " \t");
	if (!trimmed)
	{
		free_2d_array(arrays[0]);
		free_2d_array(arrays[1]);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	*rgb_value = ft_atoi(trimmed);
	free(trimmed);
}

static void	split_and_validate_colors(t_scene *scene,
	char ***temp, char ***temp2)
{
	*temp = ft_split(scene->f_color, ',');
	if (!*temp)
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	*temp2 = ft_split(scene->c_color, ',');
	if (!*temp2)
	{
		free_2d_array(*temp);
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
}

static void	parse_floor_color_components(t_scene *scene, char **temp
	, char **temp2)
{
	char	**arrays[2];

	arrays[0] = temp;
	arrays[1] = temp2;
	parse_single_color_component(temp[0], &scene->f_color_rgb[0], scene,
		arrays);
	parse_single_color_component(temp[1], &scene->f_color_rgb[1], scene,
		arrays);
	parse_single_color_component(temp[2], &scene->f_color_rgb[2], scene,
		arrays);
}

static void	parse_ceiling_color_components(t_scene *scene, char **temp
	, char **temp2)
{
	char	**arrays[2];

	arrays[0] = temp;
	arrays[1] = temp2;
	parse_single_color_component(temp2[0], &scene->c_color_rgb[0], scene,
		arrays);
	parse_single_color_component(temp2[1], &scene->c_color_rgb[1], scene,
		arrays);
	parse_single_color_component(temp2[2], &scene->c_color_rgb[2], scene,
		arrays);
}

void	parse_colors_rgb(t_scene *scene)
{
	char	**temp;
	char	**temp2;

	split_and_validate_colors(scene, &temp, &temp2);
	parse_floor_color_components(scene, temp, temp2);
	parse_ceiling_color_components(scene, temp, temp2);
	free_2d_array(temp);
	free_2d_array(temp2);
}
