/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:13:17 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:13:18 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	itrate_on_file(char *line, char *temp, int fd, t_scene *scene)
{
	while (line)
	{
		scene->file = ft_strjoin(scene->file, line);
		if (!scene->file)
		{
			print_error_type(ERR_MEMORY_ALLOCATION);
			free(temp);
			free(line);
			return (1);
		}
		free(temp);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			if (scene->file[ft_strlen(scene->file)] == '\0')
				break ;
			free(scene->file);
			print_error_type(ERR_MEMORY_ALLOCATION);
			return (1);
		}
		temp = scene->file;
	}
	return (0);
}

int	read_file(int fd, t_scene *scene)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putendl_fd("file is empty", 2);
		return (1);
	}
	scene->file = ft_strdup("");
	if (!scene->file)
	{
		print_error_type(ERR_MEMORY_ALLOCATION);
		free(line);
		return (1);
	}
	temp = scene->file;
	if (itrate_on_file(line, temp, fd, scene))
		return (1);
	return (0);
}
