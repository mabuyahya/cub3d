/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_name_and_argc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:15:58 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 12:15:59 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vname_and_vextension(int argc, char *filename)
{
	int	len;

	if (argc != 2)
		print_error_type_exit(ERR_INVALID_ARGC);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		print_error_type_exit(ERR_INVALID_EXTENSION);
}
