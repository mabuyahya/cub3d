
#include "cub3d.h"

int main(int argc, char **argv)
{
	t_scene scene;

	vname_and_vextension(argc, argv[1]);
	init_scene(argv[1],&scene);
	free_all(&scene);
	return (0);
}

