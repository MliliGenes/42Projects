# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 00:43:04 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/06 01:04:25 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_COMMON = push_swap.c \
	lib/exec/execution.c \
	lib/messages_utils/error.c \
	lib/messages_utils/ko.c \
	lib/messages_utils/ok.c \
	lib/parser_utils/ft_atol.c \
	lib/parser_utils/ft_free_split.c \
	lib/parser_utils/ft_holy_joint.c \
	lib/parser_utils/ft_int_to_stack.c \
	lib/parser_utils/ft_split.c \
	lib/parser_utils/ft_str_to_int.c \
	lib/parser_utils/ft_strchr.c \
	lib/parser_utils/ft_strcmp.c \
	lib/parser_utils/ft_strdup.c \
	lib/parser_utils/ft_strjoin.c \
	lib/parser_utils/ft_strlen.c \
	lib/parser_utils/ft_substr.c \
	lib/parser_utils/ft_validate.c \
	lib/parser_utils/ft_validate_args.c \
	lib/parser_utils/ft_word_count.c \
	lib/parser_utils/parser.c \
	lib/sort_utils/has_nums_in_range.c \
	lib/sort_utils/is_sorted.c \
	lib/sort_utils/push_back_to_a.c \
	lib/sort_utils/push_to_b.c \
	lib/sort_utils/sort.c \
	lib/stack_utils/add_back.c \
	lib/stack_utils/clear_list.c \
	lib/stack_utils/create_item.c \
	lib/stack_utils/find_max_by_index.c \
	lib/stack_utils/find_min_by_index.c \
	lib/stack_utils/list_size.c \
	lib/stack_utils/push.c \
	lib/stack_utils/reverse_rotate.c \
	lib/stack_utils/rotate.c \
	lib/stack_utils/swap.c

SRC_CHECKER = checker.c \
	get_next_line/get_next_line.c \
	lib/exec/execution.c \
	lib/messages_utils/error.c \
	lib/messages_utils/ko.c \
	lib/messages_utils/ok.c \
	lib/parser_utils/ft_atol.c \
	lib/parser_utils/ft_free_split.c \
	lib/parser_utils/ft_holy_joint.c \
	lib/parser_utils/ft_int_to_stack.c \
	lib/parser_utils/ft_split.c \
	lib/parser_utils/ft_str_to_int.c \
	lib/parser_utils/ft_strchr.c \
	lib/parser_utils/ft_strcmp.c \
	lib/parser_utils/ft_strdup.c \
	lib/parser_utils/ft_strjoin.c \
	lib/parser_utils/ft_strlen.c \
	lib/parser_utils/ft_substr.c \
	lib/parser_utils/ft_validate.c \
	lib/parser_utils/ft_validate_args.c \
	lib/parser_utils/ft_word_count.c \
	lib/parser_utils/parser.c \
	lib/sort_utils/has_nums_in_range.c \
	lib/sort_utils/is_sorted.c \
	lib/sort_utils/push_back_to_a.c \
	lib/sort_utils/push_to_b.c \
	lib/sort_utils/sort.c \
	lib/stack_utils/add_back.c \
	lib/stack_utils/clear_list.c \
	lib/stack_utils/create_item.c \
	lib/stack_utils/find_max_by_index.c \
	lib/stack_utils/find_min_by_index.c \
	lib/stack_utils/list_size.c \
	lib/stack_utils/push.c \
	lib/stack_utils/reverse_rotate.c \
	lib/stack_utils/rotate.c \
	lib/stack_utils/swap.c

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

INCLUDE = ./includes

NAME = push_swap

NAME_CHECKER = checker

RM = rm -f

all: $(NAME)

bonus : $(NAME_CHECKER)
.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ_COMMON)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJ_COMMON)

$(NAME_CHECKER): $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJ_CHECKER)

clean:
	@$(RM) $(OBJ_CHECKER) $(OBJ_COMMON)

fclean: clean
	@$(RM) $(NAME) $(NAME_CHECKER)

re : fclean all