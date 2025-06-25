

#include "cub3d.h"
int	is_delim(char ch, const char *delims)
{
	while (*delims)
	{
		if (ch == *delims)
			return (1);
		delims++;
	}
	return (0);
}

void	*free_all_split(char **f, int num)
{
	int	i = 0;
	while (i < num)
		free(f[i++]);
	free(f);
	return (NULL);
}

char	*fill_the_word(const char *s, int start, int end)
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

void	no_space(int *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

int	count_word(const char *s, const char *delims)
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
