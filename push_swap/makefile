# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 08:46:31 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/05 09:31:35 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include

BUILD_DIR = build

LIB_DIR = lib

PARSER_DIR = $(LIB_DIR)/parser
SORT_DIR = $(LIB_DIR)/sort
ERROR_DIR = $(LIB_DIR)/error
STACK_DIR = $(LIB_DIR)/stack
MOVES_DIR = $(STACK_DIR)/moves
UTILS_DIR = $(STACK_DIR)/utils

SRC_MAIN = push_swap.c

SRC_PARSER = $(PARSER_DIR)/ft_atol.c \
             $(PARSER_DIR)/ft_free_split.c \
             $(PARSER_DIR)/ft_holy_joint.c \
             $(PARSER_DIR)/ft_split.c \
             $(PARSER_DIR)/ft_str_to_int.c \
             $(PARSER_DIR)/ft_strdup.c \
             $(PARSER_DIR)/ft_strjoin.c \
             $(PARSER_DIR)/ft_strlen.c \
             $(PARSER_DIR)/ft_substr.c \
             $(PARSER_DIR)/ft_validate.c \
             $(PARSER_DIR)/ft_validate_args.c \
             $(PARSER_DIR)/ft_word_count.c \
             $(PARSER_DIR)/ft_int_to_stack.c \
             $(PARSER_DIR)/parser.c

SRC_MOVES = $(MOVES_DIR)/push.c \
            $(MOVES_DIR)/rotate.c \
            $(MOVES_DIR)/reverse_rotate.c \
            $(MOVES_DIR)/swap.c

SRC_UTILS = $(UTILS_DIR)/create_item.c \
            $(UTILS_DIR)/add_back.c \
            $(UTILS_DIR)/find_max_by_index.c \
            $(UTILS_DIR)/find_min_by_index.c \
            $(UTILS_DIR)/list_size.c \
            $(UTILS_DIR)/clear_list.c 

SRC_SORT = $(SORT_DIR)/sort.c \
            $(SORT_DIR)/push_to_b.c \
            $(SORT_DIR)/is_sorted.c \
            $(SORT_DIR)/has_nums_in_range.c \
            $(SORT_DIR)/push_back_to_a.c

SRC_ERROR = $(ERROR_DIR)/error.c

SRC = $(SRC_MAIN) $(SRC_PARSER) $(SRC_MOVES) $(SRC_UTILS) $(SRC_SORT) $(SRC_ERROR)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

NAME = push_swap

CHECKER_DIR = checker

PARSER_CHECKER_DIR = $(CHECKER_DIR)/parser
SORT_CHECKER_DIR = $(CHECKER_DIR)/sort
ERROR_CHECKER_DIR = $(CHECKER_DIR)/error
STACK_CHECKER_DIR = $(CHECKER_DIR)/stack
MOVES_CHECKER_DIR = $(STACK_CHECKER_DIR)/moves
UTILS_CHECKER_DIR = $(STACK_CHECKER_DIR)/utils

SRC_CHECKER_MAIN = checker.c

SRC_CHECKER_PARSER = $(PARSER_CHECKER_DIR)/ft_atol_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_free_split_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_holy_joint_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_split_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_str_to_int_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_strdup_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_strjoin_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_strlen_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_substr_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_validate_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_validate_args_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_word_count_bonus.c \
             $(PARSER_CHECKER_DIR)/ft_int_to_stack_bonus.c \
             $(PARSER_CHECKER_DIR)/parser_bonus.c

SRC_CHECKER_MOVES = $(MOVES_CHECKER_DIR)/push_bonus.c \
            $(MOVES_CHECKER_DIR)/rotate_bonus.c \
            $(MOVES_CHECKER_DIR)/reverse_rotate_bonus.c \
            $(MOVES_CHECKER_DIR)/swap_bonus.c

SRC_CHECKER_UTILS = $(UTILS_CHECKER_DIR)/create_item_bonus.c \
            $(UTILS_CHECKER_DIR)/add_back_bonus.c \
            $(UTILS_CHECKER_DIR)/clear_list_bonus.c 

SRC_CHECKER_SORT = $(SORT_CHECKER_DIR)/is_sorted_bonus.c \

SRC_CHECKER_ERROR = $(ERROR_CHECKER_DIR)/error_bonus.c \
					$(ERROR_CHECKER_DIR)/ok_bonus.c \
					$(ERROR_CHECKER_DIR)/ko_bonus.c


SRC_CHECKER = $(SRC_CHECKER_MAIN) $(SRCSRC_CHECKER_PARSER_PARSER) $(SRC_CHECKER_MOVES) $(SRC_CHECKER_UTILS) $(SRC_CHECKER_SORT) $(SRC_CHECKER_ERROR) 

OBJ_CHECKER = $(SRC_CHECKER:%.c=$(BUILD_DIR)/%.o)

NAME = checker

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJ) -o $(NAME)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@) # Create necessary subdirectories
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re