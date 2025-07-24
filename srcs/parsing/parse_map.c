/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:13:39 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:16:08 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	join_map_line(t_scene *scene, char **temp2, char *line)
{
	char	*temp;
	char	*new_temp2;

	free(scene->map->map);
	scene->map->map = ft_strjoin(*temp2, line);
	if (!scene->map->map)
		return (1);
	free(*temp2);
	temp = ft_strdup(scene->map->map);
	if (!temp)
		return (1);
	new_temp2 = ft_strjoin(temp, "\n");
	if (!new_temp2)
	{
		free(temp);
		return (1);
	}
	free(temp);
	*temp2 = new_temp2;
	return (0);
}

static int	get_the_map(t_scene *scene, int i, char *temp2)
{
	while (scene->file_2d[i])
	{
		if (join_map_line(scene, &temp2, scene->file_2d[i]))
		{
			free(temp2);
			return (1);
		}
		i++;
	}
	free(temp2);
	return (0);
}

int	parse_map(t_scene *scene)
{
	int		i;
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
