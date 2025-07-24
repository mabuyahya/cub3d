/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tow_d_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:48:13 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:49:04 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_strdup_2d(char **str)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * ft_strlen_2d(str));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = ft_strdup(str[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				free(copy[i - 1]);
				i--;
			}
			free(copy);
		}
		i++;
	}
	return (copy);
}

void	print_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
}
