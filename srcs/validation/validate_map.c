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
                scene->map->map_2d[i][j] != 'E' && scene->map->map_2d[i][j] != 'W')
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
}

void check_empty_lines(t_scene *scene)
{
   char *start; 
   int  i;

    start = ft_strnstr(scene->file, scene->file_2d[6], ft_strlen(scene->file));
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
                free_all_and_print_exit(scene, ERR_EMPTY_LIENES);
            }
        }
       i++;
    }
}

void validate_map(t_scene *scene)
{
    change_map_space_to_one(scene);
    check_unwanted_characters(scene);
    check_empty_lines(scene);
}