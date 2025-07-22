
#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define PI 3.14159265358979323846
#define NUM_TEXTURES 4
#define TEXTURE_SIZE 64
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_direction;

typedef struct s_scene t_scene;
typedef struct s_player t_player;

typedef struct s_map
{
	char **map_2d;
	char *map;
	int *map_lens;
	t_player *player;
}			t_map;

typedef struct s_point
{
	double x;
	double y;
} 	t_point;
 
typedef struct s_player 
{
	t_point position;
	t_point direction;
} t_player;


typedef struct s_mlx
{
	mlx_t *mlx_ptr;
	mlx_image_t	*img_ptr;
	int *img_data;
	int bpp;
	int size_line;
	int endian;
	int width;
	int height;
} t_mlx;

typedef struct s_game
{
	t_scene *scene;
	t_player	player;
	t_mlx		mlx;
	t_point		plane_vector;
	int *texture_buffer[NUM_TEXTURES];
	int **pixels_map;
} t_game;



typedef struct s_scene
{
	char *file;
	char **file_2d;
	char *f_color;
	int	f_color_rgb[3];
	char *c_color;
	int	c_color_rgb[3];
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
	ERR_UNNKNOWN_CHARACTER_IN_MAP,
	ERR_EMPTY_LIENES,
	ERR_ONLY_ONE_PLAYER,
	ERR_UNCLOSED_MAP,
	ERR_INVALID_CONTENT,
	ERR_IMAGE_NOT_FOUND,
	ERR_INVALID_COLOR,

};

#endif

