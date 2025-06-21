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
