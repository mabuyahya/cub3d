/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:50:38 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:50:39 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_struct_with_nulls(t_scene *scene)
{
	scene->file = NULL;
	scene->file_2d = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->north_image = NULL;
	scene->south_image = NULL;
	scene->west_image = NULL;
	scene->east_image = NULL;
	scene->map = malloc(sizeof(t_map));
	scene->map->map_2d = NULL;
	scene->map->map = NULL;
	scene->map->map_lens = NULL;
}

void	init_scene(char *filename, t_scene *scene)
{
	int	fd;

	init_struct_with_nulls(scene);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_all_and_print_exit(scene, ERR_FILE_NOT_FOUND);
	if (read_file(fd, scene))
	{
		close(fd);
		free_all_and_exit(scene);
	}
	if (read_2d_file(scene))
	{
		close(fd);
		free_all_and_exit(scene);
	}
	close(fd);
	if (parse_content(scene))
		free_all_and_print_exit(scene, ERR_UNNKNOWN_CHARACTER);
	if (parse_map(scene))
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	if (validate_content(scene))
		free_all_and_print_exit(scene, ERR_INVALID_CONTENT);
	validate_map(scene);
	parse_colors_rgb(scene);
}
