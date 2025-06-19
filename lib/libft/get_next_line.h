/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:19:31 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 09:44:12 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_listt
{
	char			*str_buf;
	struct s_listt	*next;
}					t_listt;

void				free_alll(t_listt **list, t_listt *new_list, char *buf);
void				last_stuff(t_listt **list);
void				cpy(t_listt *list, char *buf);
int					len_to_endline(t_listt *list);
char				*gebline(t_listt *list);
t_listt				*ft_lstlastt(t_listt *list);
int					find_endline(t_listt *list);
void				add(t_listt **list, char *buf);
void				creat_listt(t_listt **list, int fd);
char				*get_next_line(int fd);

#endif
