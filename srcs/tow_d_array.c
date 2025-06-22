#include "cub3d.h"

void print_2d_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
}