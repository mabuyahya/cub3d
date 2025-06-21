#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "stdio.h"
# include "cub3d_structs.h"

void	print_error_type_exit(int type);
void	vname_and_vextension(int argc, char *filename);
void	init_scene(char *filename, t_scene *scene);
int		read_file(int fd, t_scene *scene);
void	print_error_type(int type);
void	init_struct_with_nulls( t_scene *scene);
int		read_2dfile(t_scene *scene);
#endif
