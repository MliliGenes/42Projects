/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:42:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/11 08:02:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct list_s
{
	char			*line;
	struct list_s	*next;
}					list_t;

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, char c);
int					file_to_fd(char *path);
list_t				*create_map(char *path);
list_t				*create_list_t_node(char *line);
void				add_back_list_t(list_t **head, list_t *new_node);
void				clear_list_t_list(list_t *head);
int					parser(char *path, list_t **map);

#endif