/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:36:05 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:36:42 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all_and_print_exit_terminate(t_game *game, int error_type)
{
	print_error_type(error_type);
	free_all(game->scene);
	free_textures(game);
	free_pixel_map(game);
	mlx_terminate(game->mlx.mlx_ptr);
	exit(EXIT_FAILURE);
}

void	free_all_and_exit_terminate(t_game *game)
{
	free_all(game->scene);
	free_textures(game);
	free_pixel_map(game);
	mlx_terminate(game->mlx.mlx_ptr);
	exit(EXIT_FAILURE);
}
