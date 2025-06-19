/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:29:57 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 09:49:47 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_listt	*ft_lstlastt(t_listt *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	find_endline(t_listt *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	add(t_listt **list, char *buf)
{
	t_listt	*new_node;
	t_listt	*last_node;

	last_node = ft_lstlastt(*list);
	new_node = malloc(sizeof(t_listt));
	if (NULL == new_node)
	{
		*list = NULL;
		return ;
	}
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	creat_listt(t_listt **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!(find_endline(*list)))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
		{
			*list = NULL;
			return ;
		}
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read || char_read == -1)
		{
			free(buf);
			buf = NULL;
			return ;
		}
		buf[char_read] = '\0';
		add(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_listt	*list = NULL;
	char			*next_lline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	creat_listt(&list, fd);
	if (list == NULL)
		return (NULL);
	next_lline = gebline(list);
	last_stuff(&list);
	return (next_lline);
}
/*int	main(void)
{
	char	*line;
	int	fd;
	int	i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		free(line);
		i++;
	}
	return (0);
}*/
