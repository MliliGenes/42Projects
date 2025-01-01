/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:31:37 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 00:09:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../include/push_swap.h"

long	ft_atol(const char *nptr, int *is_valid);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_word_count(char *s, char sep);
char	*ft_holy_joint(char **argv);
int		ft_validate(char *joined_argv);
int		ft_validate_args(char **num);
int		*ft_str_to_int(char **strs, int ints);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif