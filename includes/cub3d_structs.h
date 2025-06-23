
#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_player
{
	int x;
	int y;
	char direction;
}			t_player;

typedef struct s_map
{
	char **map_2d;
	char *map;
	t_player *player;
}			t_map;

typedef struct s_scene
{

	char *file;
	char **file_2d;
	char *f_color;
	char *c_color;
	char *north_image;
	char *south_image;
	char *west_image;
	char *east_image;
	t_map *map;
}			t_scene;

enum e_errors
{
	ERR_INVALID_EXTENSION = 1,
	ERR_INVALID_ARGC,
	ERR_FILE_NOT_FOUND,
	ERR_MEMORY_ALLOCATION,
	ERR_FILE_NOT_COMPLETED,
	ERR_UNNKNOWN_CHARACTER,

};
#endif
