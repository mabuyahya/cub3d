#include "cub3d.h"

int ft_strlen_2d(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char **ft_strdup_2d(char **str)
{
    int i;
    char **copy;

    i = 0;
    copy = malloc(sizeof(char *) * ft_strlen_2d(str));
    if (!copy)
        return (NULL);
    while (str[i])
    {
        copy[i] = ft_strdup(str[i]);
        if (!copy[i])
        {
            while (i > 0)
            {
                free(copy[i - 1]);
                i--;
            }
            free(copy);
        }
        i++;
    }
    return (copy);
}

void print_2d_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
}