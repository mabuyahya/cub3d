/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:35:05 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 09:46:56 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_file_parsing_errors(int type)
{
	if (type == ERR_INVALID_EXTENSION)
		ft_putstr_fd("Error: Invalid file extension. Expected .cub\n", 2);
	else if (type == ERR_FILE_NOT_FOUND)
		ft_putstr_fd("Error: File not found\n", 2);
	else if (type == ERR_MEMORY_ALLOCATION)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (type == ERR_INVALID_ARGC)
		ft_putstr_fd("Error:Invalid arguments number\n",
			2);
	else if (type == ERR_FILE_NOT_COMPLETED)
		ft_putstr_fd("Error: File not completed.Check the file content\n",
			2);
	else if (type == ERR_UNNKNOWN_CHARACTER)
		ft_putstr_fd("Error: Unknown character or dublicate in the file\n", 2);
	else if (type == ERR_INVALID_CONTENT)
		ft_putstr_fd("Error: Invalid content in the file\n", 2);
	else if (type == ERR_IMAGE_NOT_FOUND)
		ft_putstr_fd("Error: Image file not found\n", 2);
	else if (type == ERR_INVALID_COLOR)
		ft_putstr_fd("Error: Invalid color format/malloc faild\n", 2);
	else
		ft_putstr_fd("Error: Unknown error\n", 2);
}

static void	print_map_errors(int type)
{
	if (type == ERR_UNNKNOWN_CHARACTER_IN_MAP)
		ft_putstr_fd("Error: Unknown character the map\n", 2);
	else if (type == ERR_EMPTY_LIENES)
		ft_putstr_fd("Error: empty line in the map\n", 2);
	else if (type == ERR_ONLY_ONE_PLAYER)
		ft_putstr_fd("Error: the map should contain one player\n", 2);
	else if (type == ERR_UNCLOSED_MAP)
		ft_putstr_fd("Error: the map should be closed/surrounded\n", 2);
}

void	check_what_type(int type)
{
	if (type == ERR_UNNKNOWN_CHARACTER_IN_MAP || type == ERR_EMPTY_LIENES
		|| type == ERR_ONLY_ONE_PLAYER || type == ERR_UNCLOSED_MAP)
		print_map_errors(type);
	else
		print_file_parsing_errors(type);
}

void	print_error_type(int type)
{
	check_what_type(type);
}

void	print_error_type_exit(int type)
{
	check_what_type(type);
	exit(EXIT_FAILURE);
}
