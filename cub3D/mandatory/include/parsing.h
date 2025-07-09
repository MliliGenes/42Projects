/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:34:22 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:17:56 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

size_t		ft_strlen(const char *s);
int			ft_up_down(char *ptr, int i);
void		ft_freeing(char **arr);
t_map		*full_members(char **map, t_utils *utils);
int			ft_nsea(char *map);
int			index_map_p(char *map);
void		free_help(t_utils *utils);
void		ft_map_parse_free(t_map *parse);
void		ft_utils_free(t_utils *utils);
int			sil_count(char **arr, int k, int i);
void		parsiixx_freex(t_map *parse);
void		skiiipox(char **arr, t_help *help, int i);
int			ft_checking_close_map(char **map);
int			ft_cheking_nsew(char **arr, int i);
void		lenght_sk(t_help *help, char **arr, int i);
char		*cpy_help_norm(char **arr, t_help *help, int i, char *ptr);
char		**ft_cheking_fc(char **arr, int i, int k);
void		*ft_void_free(t_utils *utils);
t_utils		*utils_ret(char *coor[4], t_norm *norm, char **arr);
char		*ft_strnstr(const char *hay, const char *need, size_t len);
void		parse_free(t_map *parse);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
t_map		*parse_colors_utils_norm(t_map *parse, t_utils *utils);
t_map		*ret_help(char **map);
t_map		*ret_first_help(char *ptr, char **arr);
char		*read_line_hh(int fd);
int			find_map(char *ptr, int i);
int			ft_cheking_nsew(char **arr, int i);
char		**ft_checking_nwl(char *ptr, char **arr);
int			ft_check_emptyline(char *ptr, int *i);
void		ft_initialse_flags(t_norm *norm);
int			ft_norm_gg_codex(t_utils *utils, char **arr, t_norm *norm);
char		*break_lines(char **arr, t_norm *norm, t_utils *utils);
int			ft_valide_lines(char *ptr);
int			ft_count(char const *str, char c);
long long	ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
int			ft_check_dot(char *path);
void		allocation_manager(int fd, char **save);
int			ft_newline_check(char *string);
void		*ft_cpy(char *string, char *string1, int n);
int			ft_invalid_map(char *map);
void		ft_freeing(char **arr);
char		*ft_copy_st(char *start, int len, int j, char *ptr);
char		*ft_strcat(char *string1, char *string2);
int			ft_sstrlen(char *string);
char		*get_next_line(int fd);
t_map		*parse_map_file(char *path);
char		**ft_split(char const *s, char c);
t_utils		*ft_checking_the_four(char **arr);
char		**ft_cheking_fc(char **arr, int i, int k);
char		*ft_strdup(const char *s1);
void		free_help(t_utils *utils);
int			first_line(char *map);
int			ft_closed_door(char **map);
int			ft_if_lot(char **map, int i, int j);
int			ft_the_big_size(char *ptr, int i);
int			extract_line(char *ptr, int i);
int			ft_countix(char *ptr, int start);
int			ft_if_lot_2(char **map, int i, int j);
char		**ft_fill_space(char **map, int size);
int			norminette_help_close(char **map, int i, int j, int size);
int			ft_closing(char **map);
int			ft_checking_close_map(char **map);
int			ft_check_valid_path(char *ptr, char *str, char *clr, char *codex);
#endif