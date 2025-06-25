#include "cub3d.h"

void check_what_type(int type)
{
	if (type == ERR_INVALID_EXTENSION)
		ft_putstr_fd("Error: Invalid file extension. Expected .cub\n", 2);
	else if (type == ERR_FILE_NOT_FOUND)
		ft_putstr_fd("Error: File not found\n", 2);
	else if (type == ERR_MEMORY_ALLOCATION)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (type == ERR_INVALID_ARGC)
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./cub3d <map_file.cub>\n", 2);
	else if (type == ERR_FILE_NOT_COMPLETED)
		ft_putstr_fd("Error: File not completed. Check the content of the file\n", 2);
	else if (type == ERR_UNNKNOWN_CHARACTER)
		ft_putstr_fd("Error: Unknown character or dublicate in the file\n", 2);
	else if (type == ERR_UNNKNOWN_CHARACTER_IN_MAP)
		ft_putstr_fd("Error: Unknown character the map\n", 2);
	else if (type == ERR_EMPTY_LIENES)
		ft_putstr_fd("Error: empty line in the map\n", 2);
	else if (type == ERR_ONLY_ONE_PLAYER)
		ft_putstr_fd("Error: the map should contain one player\n", 2);
	else if (type == ERR_UNCLOSED_MAP)
		ft_putstr_fd("Error: the map should be closed/surrounded\n", 2);
	else if (type == ERR_INVALID_CONTENT)
		ft_putstr_fd("Error: Invalid content in the file\n", 2);
	else if (type == ERR_IMAGE_NOT_FOUND)
		ft_putstr_fd("Error: Image file not found\n", 2);
	else if (type == ERR_INVALID_COLOR)
		ft_putstr_fd("Error: Invalid color format\n", 2);
	else
		ft_putstr_fd("Error: Unknown error\n", 2);
}

void print_error_type(int type)
{
	check_what_type(type);
}

void print_error_type_exit(int type)
{
	check_what_type(type);
	exit(EXIT_FAILURE);
}
