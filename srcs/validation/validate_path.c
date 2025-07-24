/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:16:05 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 12:17:37 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_path(char *path, t_scene *scene)
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

int	*get_map_lens(t_scene *scene)
{
	int	*len;
	int	i;

	i = 0;
	len = malloc(sizeof(int) * ft_strlen_2d(scene->map->map_2d) + 1);
	if (!len)
	{
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	while (scene->map->map_2d[i])
	{
		len[i] = ft_strlen(scene->map->map_2d[i]);
		i++;
	}
	return (len);
}
