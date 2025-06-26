#include "cub3d.h"

void check_unwanted_characters(t_scene *scene)
{
    int i;
    int j;

    i = 0;
    while (scene->map->map_2d[i])
    {
        j = 0;
        while (scene->map->map_2d[i][j])
        {
            if (scene->map->map_2d[i][j] != '0' && scene->map->map_2d[i][j] != '1' &&
                scene->map->map_2d[i][j] != 'N' && scene->map->map_2d[i][j] != 'S' &&
                scene->map->map_2d[i][j] != 'E' && scene->map->map_2d[i][j] != 'W' &&
                scene->map->map_2d[i][j] != ' ')
            {
                free_all_and_print_exit(scene, ERR_UNNKNOWN_CHARACTER_IN_MAP);
            }
            j++;
        }
        i++;
    }
}

void change_map_space_to_one(t_scene *scene)
{
    int i;
    int j;

    i = 0;
    while(scene->map->map_2d[i])
    {
        j = 0;
        while(scene->map->map_2d[i][j]) 
        {
            if (scene->map->map_2d[i][j] == ' ')
                scene->map->map_2d[i][j] = '1';
            j++;
        }
        i++;
    }
    i = 0;
    while (scene->map->map[i])
    {
        if (scene->map->map[i] == ' ')
        {
            scene->map->map[i] = '1';
        }
        i++;
    }
}

void check_empty_lines(t_scene *scene)
{
   char *start; 
   char *temp; 
   int  i;

    temp = ft_strnstr(scene->file, scene->file_2d[6], ft_strlen(scene->file));
    start = ft_strtrim(temp, "\n");
    
    i = 0;
    while (start[i])
    {
        if (start[i] == '\n')
        {
            i++;
            while (start[i] && (start[i] == ' ' || start[i] == '\t'))
            {
                i++;
            }
            if (start[i] == '\n')
            {
                free(start);
                free_all_and_print_exit(scene, ERR_EMPTY_LIENES);
            }
        }
        if (start[i])
            i++;
    }
    free(start);
}

void check_only_one_player(t_scene *scene)
{
    int i;
    int player_count;

    i = 0;
    player_count = 0;
    while (scene->map->map[i])
    {
        if (scene->map->map[i] == 'N' || scene->map->map[i] == 'S' ||
            scene->map->map[i] == 'E' || scene->map->map[i] == 'W')
        {
            player_count++;
        }
        i++;
    }
    if  (player_count != 1)
    {
        free_all_and_print_exit(scene, ERR_ONLY_ONE_PLAYER);
    }
}

int *get_map_lens(t_scene *scene)
{
	int *len;
	int i;

	i = 0;
	len = malloc(sizeof(int) * ft_strlen_2d(scene->map->map_2d) + 1); 
	if (!len)
	{
		free_all_and_print_exit(scene, ERR_MEMORY_ALLOCATION);
	}
	while (scene->map->map_2d[i])
	{
		len[i] = ft_strlen(scene->map->map_2d[i]);
		i++;
	}
	return (len);
}

void validate_map(t_scene *scene)
{
    check_unwanted_characters(scene);
    check_empty_lines(scene);
    check_only_one_player(scene);
    scene->map->map_lens = get_map_lens(scene);
    check_closeness(scene);
    change_map_space_to_one(scene);
    // printf("Map:\n%s\n", scene->map->map);
    // printf("Map2d:\n");
    // print_2d_array(scene->map->map_2d);
}