/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:42:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/22 19:55:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "structs.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ************************************************************************** */
/*                            FILE HANDLING FUNCTIONS                         */
/* ************************************************************************** */

char	*get_next_line(int fd);
int		file_to_fd(char *path);
void	*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                            STRING UTILITIES                                */
/* ************************************************************************** */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, char c);
void	ft_putnbr(int n);

/* ************************************************************************** */
/*                              LIST UTILITIES                                */
/* ************************************************************************** */

t_list	*create_t_list_node(char *line);
void	add_back_t_list(t_list **head, t_list *new_node);
void	clear_t_list_list(t_list *head);
int		list_length(t_list *list);
t_list	*list_dup(t_list *list);

/* ************************************************************************** */
/*                            MAP HANDLING FUNCTIONS                          */
/* ************************************************************************** */

t_list	*create_map(char *path);
int		parser(char *path, t_map **map);
int		is_map_enclosed(t_list *map);
int		search_in_map(t_list *map, char to_find);

/* ************************************************************************** */
/*                          VALIDATION FUNCTIONS                              */
/* ************************************************************************** */

void	flood_fill_validate(t_list *node, int x, t_validate *result);
void	find_pos_in_map(t_list *map, t_play_pos *pos);

/* ************************************************************************** */
/*                          ERROR HANDLING                                    */
/* ************************************************************************** */

void	error(char *message);

#endif