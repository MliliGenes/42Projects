/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:42:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 09:50:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "structs.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ************************************************************************** */
/*                            FILE HANDLING FUNCTIONS                         */
/* ************************************************************************** */

char				*get_next_line(int fd);
int					file_to_fd(char *path);
void				*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                            STRING UTILITIES                                */
/* ************************************************************************** */

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, char c);

/* ************************************************************************** */
/*                              LIST UTILITIES                                */
/* ************************************************************************** */

list_t				*create_list_t_node(char *line);
void				add_back_list_t(list_t **head, list_t *new_node);
void				clear_list_t_list(list_t *head);
int					list_length(list_t *list);
list_t				*list_dup(list_t *list);

/* ************************************************************************** */
/*                            MAP HANDLING FUNCTIONS                          */
/* ************************************************************************** */

list_t				*create_map(char *path);
int					parser(char *path, list_t **map);
int					is_map_enclosed(list_t *map);
int					search_in_map(list_t *map, char to_find);

/* ************************************************************************** */
/*                          VALIDATION FUNCTIONS                              */
/* ************************************************************************** */

void				flood_fill_validate(list_t *node, int x,
						validate_t *result);
void				find_pos_in_map(list_t *map, play_pos_t *pos);

/* ************************************************************************** */
/*                          ERROR HANDLING                                    */
/* ************************************************************************** */

void				error(char *message);

#endif