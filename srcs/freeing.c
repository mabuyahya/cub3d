#include "cub3d.h" 

// we will but here the things that need to be freed so we won't forget to free anything
/*
scene->file
scene->file_2d
*/

void free_all(t_scene *scene)
{
    if (scene->file)
        free(scene->file);
    if (scene->file_2d)
        free_2d_array(scene->file_2d);
}

void free_all_and_exit(t_scene *scene)
{
    free_all(scene);
    exit(EXIT_FAILURE);
}

void free_2d_array(char **array)
{
    int i;

    if (!array)
        return;
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}