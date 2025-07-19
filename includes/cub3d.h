#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <math.h>
# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "stdio.h"
# include <string.h>
# include "cub3d_structs.h"

// main folder
void	print_error_type_exit(int type);
void	print_error_type(int type);
void	print_2d_array(char **array);
void	free_2d_array(char **array);
void	 free_all_and_exit(t_scene *scene);
void	free_all_and_print_exit(t_scene *scene, int error_type);
void	free_all(t_scene *scene);
int ft_strlen_2d(char **str);
void free_all_and_exit_terminate(t_game *game);
void free_all_and_print_exit_terminate(t_game *game, int error_type);
char **ft_strdup_2d(char **str);
// validation folder
void check_closeness(t_scene *scene);
void    validate_map(t_scene *scene);
void	vname_and_vextension(int argc, char *filename);
char	**terpo_split(const char *s, const char *delims);
int		validate_element(char **element, int is_image, t_scene *scene);
int		validate_content(t_scene *scene);
int		validate_path(char *path, t_scene *scene);
int		validate_color(char *color);
int		convert_color(char *str);
int		len_of_array(char **array);
// parsing folder
void	init_scene(char *filename, t_scene *scene);
int		read_file(int fd, t_scene *scene);
int		read_2d_file(t_scene *scene);
int		parse_content(t_scene *scene);
int		parse_map(t_scene *scene);
void    parse_colors_rgb(t_scene *scene);
// utilities folder
void change_map_space_to_zeros(t_scene *scene);
int	is_delim(char ch, const char *delims);
void	*free_all_split(char **f, int num);
char	*fill_the_word(const char *s, int start, int end);
void	no_space(int *i, int *j, int *start_word);
int		count_word(const char *s, const char *delims);
//ray casting folder
void	mlx_setup(t_game *game);
void	get_raycasting_info(t_game *game);
void	get_plane(t_game *game);
void    game_setup(t_game *game);
void	ray_casting(t_game *game);
void	init_textures(t_game *game);
void	load_texture_to_buffer(t_game *game, char *path, int texture_index);
void	init_pixel_map(t_game *game);
void	free_textures(t_game *game);
void	free_pixel_map(t_game *game);
t_cardinal_direction	get_cardinal_direction(int side, double ray_dir_x, double ray_dir_y);
void	render_frame(t_game *game);
// controls folder
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	handle_keypress(mlx_key_data_t keydata, void *param);
void	handle_close(void *param);

#endif
