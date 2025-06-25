#include "cub3d.h"


// get the x and y 
// make a copy of the map
// give the copy map for the flood fill
// if you can exit the map then stop everything 
// if not move to the next position




// void get_map_copy(t_scene *scene,char  ***copy_map)
// {
//     *copy_map = ft_strdup_2d(scene->map->map_2d);
// }
//  || y < 0 || y > ft_strlen_2d(scene->map->map_2d)

void check_within_boundaries(t_scene *scene, int x, int y)
{
    (void) x;
    if (y == 0 || y == ft_strlen_2d(scene->map->map_2d) - 1)
        free_all_and_print_exit(scene, ERR_UNCLOSED_MAP);
    if (scene->map->map_lens[y - 1] < (x + 1) || scene->map->map_2d[y - 1][x] == 0)
            free_all_and_print_exit(scene, ERR_UNCLOSED_MAP);
    if (scene->map->map_lens[y + 1] < (x + 1) || scene->map->map_2d[y + 1][x] == 0)
            free_all_and_print_exit(scene, ERR_UNCLOSED_MAP);
}

void flood_fill(t_scene *scene, int x, int y)
{
    if (x == (int )ft_strlen(scene->map->map_2d[y]) && scene->map->map_2d[y][x] == '0')
        free_all_and_print_exit(scene, ERR_UNCLOSED_MAP);
    if (x < 0 || x > (int )ft_strlen(scene->map->map_2d[y]) || y < 0 || y > ft_strlen_2d(scene->map->map_2d))
        return ;
    if (scene->map->map_2d[y][x] != '1')
    {
        check_within_boundaries(scene, x, y);
        return ;
    }
    flood_fill(scene, ++x, y);
    flood_fill(scene, --x, y);
    flood_fill(scene, x, ++y);
    flood_fill(scene, x, --y);

}

void check_closeness(t_scene *scene)
{
    t_pair o;

    o.x = 0;
    o.y = 0;
    while(scene->map->map_2d[o.y]) 
    {
        o.x = 0;
        while (scene->map->map_2d[o.y][o.x])
        {
            if (scene->map->map_2d[o.y][o.x] != '1')
            {
                flood_fill(scene, o.x, o.y);
            }
            o.x++;
        }
        o.y++;
    }
}