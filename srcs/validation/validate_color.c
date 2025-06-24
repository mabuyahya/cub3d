#include "cub3d.h"

int	convert_color(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

int len_of_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}



int validate_color(char *color)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(color, ',');
	i = len_of_array(temp);
	if (i != 3)
	{
		free_2d_array(temp);
		return (1);
	}
	i = 0;
	while (temp[i])
	{
		if (convert_color(temp[i]) == -1)
		{
			free_2d_array(temp);
			return (1);
		}
		if (ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
		{
			free_2d_array(temp);
			return (1);
		}
		i++;
	}
	free_2d_array(temp);
	return (0);
}
