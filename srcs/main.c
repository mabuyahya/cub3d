
#include "cub3d.h"

int	vname_and_vextension(int argc, char *filename)
{
	int	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <map_file.cub>\n", 2);
		return (0);
	}
	len = ft_strlen(filename);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension. Expected .cub\n", 2);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{

	if (!vname_and_vextension(argc, argv[1]))
		return (1);
	printf("Valid file name and extension.\n");
	return (0);
}

