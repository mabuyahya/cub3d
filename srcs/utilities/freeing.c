/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:29:59 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:36:55 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_scene_data(t_scene *scene)
{
	if (scene->file)
		free(scene->file);
	if (scene->file_2d)
		free_2d_array(scene->file_2d);
	if (scene->f_color)
		free(scene->f_color);
	if (scene->c_color)
		free(scene->c_color);
	if (scene->north_image)
		free(scene->north_image);
	if (scene->south_image)
		free(scene->south_image);
	if (scene->west_image)
		free(scene->west_image);
	if (scene->east_image)
		free(scene->east_image);
}

static void	free_map_data(t_scene *scene)
{
	if (scene->map)
	{
		if (scene->map->map_2d)
			free_2d_array(scene->map->map_2d);
		if (scene->map->map)
			free(scene->map->map);
		if (scene->map->map_lens)
			free(scene->map->map_lens);
		free(scene->map);
	}
}

void	free_all(t_scene *scene)
{
	free_scene_data(scene);
	free_map_data(scene);
}

void	free_all_and_exit(t_scene *scene)
{
	free_all(scene);
	exit(EXIT_FAILURE);
}

void	free_all_and_print_exit(t_scene *scene, int error_type)
{
	print_error_type(error_type);
	free_all(scene);
	exit(EXIT_FAILURE);
}
