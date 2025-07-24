/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:47:35 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/07/24 10:42:27 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	i = 0;
	while (i < num)
		free(f[i++]);
	free(f);
	return (NULL);
}

char	*fill_the_word(const char *s, int start, int end)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(end - start + 1);
	if (!c)
		return (NULL);
	while (start < end)
		c[i++] = s[start++];
	c[i] = '\0';
	return (c);
}

int	no_space(int *i, int *j, int *start_word, char ***f, char *s)
{
	*f = ft_calloc(count_word(s, " \t") + 1, sizeof(char *));
	if (!*f)
		return (0);
	*i = 0;
	*j = 0;
	*start_word = -1;
	return (1);
}

int	count_word(const char *s, const char *delims)
{
	int	num;
	int	trigger;
	int	i;

	num = 0;
	trigger = 0;
	i = 0;
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
