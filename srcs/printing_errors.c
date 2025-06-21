#include "cub3d.h"

void print_error_type(int type)
{
	if (type == ERR_INVALID_EXTENSION)
		ft_putstr_fd("Error: Invalid file extension. Expected .cub\n", 2);
	else if (type == ERR_FILE_NOT_FOUND)
		ft_putstr_fd("Error: File not found\n", 2);
	else if (type == ERR_MEMORY_ALLOCATION)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (type == ERR_INVALID_ARGC)
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./cub3d <map_file.cub>\n", 2);
	else
		ft_putstr_fd("Error: Unknown error\n", 2);
}

void print_error_type_exit(int type)
{
	if (type == ERR_INVALID_EXTENSION)
		ft_putstr_fd("Error: Invalid file extension. Expected .cub\n", 2);
	else if (type == ERR_FILE_NOT_FOUND)
		ft_putstr_fd("Error: File not found\n", 2);
	else if (type == ERR_MEMORY_ALLOCATION)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (type == ERR_INVALID_ARGC)
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./cub3d <map_file.cub>\n", 2);
	else
		ft_putstr_fd("Error: Unknown error\n", 2);
	exit(EXIT_FAILURE);
}
