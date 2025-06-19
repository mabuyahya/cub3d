/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:59:30 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 09:48:42 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_alll(t_listt **list, t_listt *new_list, char *buf)
{
	t_listt	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buf);
		(*list)->str_buf = NULL;
		free(*list);
		*list = NULL;
		*list = temp;
	}
	*list = NULL;
	if (new_list->str_buf[0])
	{
		*list = new_list;
	}
	else
	{
		free(buf);
		buf = NULL;
		free(new_list);
		new_list = NULL;
	}
}

void	last_stuff(t_listt **list)
{
	t_listt	*last_listt;
	t_listt	*new_list;
	int		j;
	int		i;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	new_list = malloc(sizeof(t_listt));
	if (buf == NULL || new_list == NULL)
	{
		*list = NULL;
		return ;
	}
	last_listt = ft_lstlastt(*list);
	i = 0;
	j = 0;
	while (last_listt->str_buf[i] && last_listt->str_buf[i] != '\n')
		++i;
	while (last_listt->str_buf[i] && last_listt->str_buf[++i])
		buf[j++] = last_listt->str_buf[i];
	buf[j] = '\0';
	new_list->str_buf = buf;
	new_list->next = NULL;
	free_alll(list, new_list, buf);
}

void	cpy(t_listt *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_endline(t_listt *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

char	*gebline(t_listt *list)
{
	int		str_len;
	char	*f_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_endline(list);
	f_str = malloc(str_len + 1);
	if (NULL == f_str)
	{
		list = NULL;
		return (NULL);
	}
	cpy(list, f_str);
	return (f_str);
}
