/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../include/push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:50:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 14:56:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

typedef struct s_item
{
	int				value;
	int				index;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

long				ft_atol(const char *nptr, int *is_valid);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
int					ft_word_count(char *s, char sep);
char				*ft_holy_joint(char **argv);
int					ft_validate(char *joined_argv);
int					ft_validate_args(char **num);
int					ft_str_to_int(int *int_arr, char **strs, int ints);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_free_split(char **split);
int					parser(int argc, char **argv);

void				sa(t_item **head);
void				sb(t_item **head);
void				ss(t_item **head_a, t_item **head_b);
void				pa(t_item **head_a, t_item **head_b);
void				pb(t_item **head_b, t_item **head_a);
void				ra(t_item **head_a);
void				rb(t_item **head_b);
void				rr(t_item **head_a, t_item **head_b);

#endif