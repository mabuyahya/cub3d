/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:51:04 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:02:22 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_texture_or_color(char *line, t_scene *scene)
{
	if (ft_strncmp(line, "F", 1) == 0 && scene->f_color == NULL)
		scene->f_color = line;
	else if (ft_strncmp(line, "C", 1) == 0 && scene->c_color == NULL)
		scene->c_color = line;
	else if (ft_strncmp(line, "NO", 2) == 0 && scene->north_image == NULL)
		scene->north_image = line;
	else if (ft_strncmp(line, "SO", 2) == 0 && scene->south_image == NULL)
		scene->south_image = line;
	else if (ft_strncmp(line, "WE", 2) == 0 && scene->west_image == NULL)
		scene->west_image = line;
	else if (ft_strncmp(line, "EA", 2) == 0 && scene->east_image == NULL)
		scene->east_image = line;
	else
		return (0);
	return (1);
}

static int	check_for_duplicates(char *line)
{
	if (ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

static int	check_for_map_start(char *line)
{
	if (line[0] == '1' || line[0] == '0')
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static int	handle_unmatched_line(char *line)
{
	if (check_for_duplicates(line))
		return (1);
	return (check_for_map_start(line));
}

int	parse_content(t_scene *scene)
{
	int		i;
	char	*line;

	if (!scene || !scene->file_2d)
		return (1);
	i = 0;
	while (scene->file_2d[i])
	{
		line = ft_strtrim(scene->file_2d[i], " \t");
		if (parse_texture_or_color(line, scene))
		{
			i++;
			continue ;
		}
		return (handle_unmatched_line(line));
	}
	return (1);
}
