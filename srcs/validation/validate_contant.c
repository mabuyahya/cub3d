
#include "cub3d.h"

// this function for validating the content of the scene exept map



static int	is_delim(char ch, const char *delims)
{
	while (*delims)
	{
		if (ch == *delims)
			return (1);
		delims++;
	}
	return (0);
}

static void	*free_all(char **f, int num)
{
	int	i = 0;
	while (i < num)
		free(f[i++]);
	free(f);
	return (NULL);
}

static char	*fill_the_word(const char *s, int start, int end)
{
	char	*c;
	int		i = 0;

	c = malloc(end - start + 1);
	if (!c)
		return (NULL);
	while (start < end)
		c[i++] = s[start++];
	c[i] = '\0';
	return (c);
}

static void	no_space(int *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

static int	count_word(const char *s, const char *delims)
{
	int	num = 0;
	int	trigger = 0;
	int	i = 0;

	while (s[i])
	{
		if (!is_delim(s[i], delims) && trigger == 0)
		{
			num++;
			trigger = 1;
		}
		else if (is_delim(s[i], delims))
			trigger = 0;
		i++;
	}
	return (num);
}

char	**terpo_split(const char *s, const char *delims)
{
	char	**f;
	int		i, j, start_word;

	no_space(&i, &j, &start_word);
	f = ft_calloc(count_word(s, delims) + 1, sizeof(char *));
	if (!f)
		return (NULL);
	while ((size_t)i <= ft_strlen(s))
	{
		if (!is_delim(s[i], delims) && start_word < 0)
			start_word = i;
		else if ((is_delim(s[i], delims) || (size_t)i == ft_strlen(s)) && start_word >= 0)
		{
			f[j] = fill_the_word(s, start_word, i);
			if (!f[j])
				return (free_all(f, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	f[j] = NULL;
	return (f);
}

int validate_element (char *element)
{
	char **temp;

	temp = terpo_split(element, " \t");
	if (temp[3])
	{
		free_2d_array(temp);
		return (1);
	}
	free_2d_array(temp);
}

int	validate_content(t_scene *scene)
{
	if (!(scene->f_color || scene->c_color
		|| scene->north_image || scene->south_image
		|| scene->west_image || scene->east_image))
	{
		free_all_and_print_exit(scene, ERR_FILE_NOT_COMPLETED);
	}
	if (validate_element(scene->f_color) ||
		validate_element(scene->c_color) ||
		validate_element(scene->north_image) ||
		validate_element(scene->south_image) ||
		validate_element(scene->west_image) ||
		validate_element(scene->east_image))
	{
		// print_error_type(ERR_UNNKNOWN_CHARACTER);
		return (1);
	}

}
