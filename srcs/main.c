
#include "cub3d.h"

int main(int argc, char **argv)
{

	if (!vname_and_vextension(argc, argv[1]))
		return (1);
	printf("Valid file name and extension.\n");
	return (0);
}

