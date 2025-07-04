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
	char	*trimmed;
	int		i;

	i = -1;
	if (color[0] == ',' || color[ft_strlen(color) - 1] == ',')
		return (1);
	while (color[++i])
		if (i != 0 && color[i] == ',' && color[i - 1] == ',')
			return (1);
	temp = ft_split(color, ',');
	if (!temp)
		return (1);
	i = len_of_array(temp);
	if (i != 3)
	{
		free_2d_array(temp);
		return (1);
	}
	i = 0;
	while (temp[i])
	{
		trimmed = ft_strtrim(temp[i], " \t");
		if (!trimmed)
		{
			free_2d_array(temp);
			return (1);
		}
		if (convert_color(trimmed) == -1)
		{
			free(trimmed);
			free_2d_array(temp);
			return (1);
		}
		if (ft_atoi(trimmed) < 0 || ft_atoi(trimmed) > 255)
		{
			free(trimmed);
			free_2d_array(temp);
			return (1);
		}
		free(trimmed);
		i++;
	}
	free_2d_array(temp);
	return (0);
}
