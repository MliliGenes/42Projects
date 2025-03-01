/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:07:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/12 23:44:13 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_function_entry
{
	char					flag;
	int						(*function)(va_list args);
	struct s_function_entry	*next;
}							t_function_entry;
t_function_entry			*new_node(char flag, int (*function)(va_list));
void						add_back(t_function_entry **lst,
								t_function_entry *new_node);
void						put_char(char c);
int							put_char_func(va_list args);
int							put_str_func(va_list args);
int							putnbr_func(va_list args);
int							putunsigned_func(va_list args);
int							puthex_lower_func(va_list args);
int							puthex_upper_func(va_list args);
int							putpointer_func(va_list args);
int							ft_printf(const char *format, ...);
void						putnbr_rec_func(unsigned int n, int *count);
void						puthex_rec_func(unsigned int nb, int is_toupper,
								int *count);
void						putpointer_rec_func(unsigned long nb,
								int is_toupper, int *count);
t_function_entry			*init_functions(void);
void						free_list(t_function_entry *head);
#endif