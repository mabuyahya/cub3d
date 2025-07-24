/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2d_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:13:00 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:13:02 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_2d_file(t_scene *scene)
{
	scene->file_2d = ft_split(scene->file, '\n');
	if (!scene->file_2d)
	{
		print_error_type(ERR_MEMORY_ALLOCATION);
		free(scene->file);
		return (1);
	}
	return (0);
}
