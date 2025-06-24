#include "cub3d.h"


// get the x and y 
// make a copy of the map
// give the copy map for the flood fill
// if you can exit the map then stop everything 
// if not move to the next position




void get_map_copy(t_scene *scene,char  ***copy_map)
{
    *copy_map = ft_strdup_2d(scene->map->map_2d);
}

void flood_fill(t_scene *scene, int x, int y)
{
    printf("%i %i\n", x, y);
    if (x < 0 || x > (int )ft_strlen(scene->map->map_2d[y]) || y < 0 || y > ft_strlen_2d(scene->map->map_2d))
        return ;
    flood_fill(scene, ++x, y);
    flood_fill(scene, --x, y);
    flood_fill(scene, x, ++y);
    flood_fill(scene, x, --y);

}

void check_closeness(t_scene *scene)
{
    t_pair o;

    // print_2d_array(scene->map->map_2d);
        
    o.x = 0;
    o.y = 0;
    while(scene->map->map_2d[o.y]) 
    {
        o.x = 0;
        while (scene->map->map_2d[o.x])
        {
            if (scene->map->map_2d[o.y][o.x] == '0')
            {
                flood_fill(scene, o.x, o.y);
            }
            o.x++;
        }
        o.y++;
    }
}