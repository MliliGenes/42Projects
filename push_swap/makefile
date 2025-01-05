# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 06:34:11 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/05 06:48:59 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

SRC_CHECKER = ./checker.c \
            ./checker/error/error_bonus.c \
            ./checker/error/ko_bonus.c \
            ./checker/error/ok_bonus.c \
            ./checker/parser/ft_atol_bonus.c \
            ./checker/parser/ft_free_split_bonus.c \
            ./checker/parser/ft_holy_joint_bonus.c \
            ./checker/parser/ft_int_to_stack_bonus.c \
            ./checker/parser/ft_split_bonus.c \
            ./checker/parser/ft_str_to_int_bonus.c \
            ./checker/parser/ft_strdup_bonus.c \
            ./checker/parser/ft_strjoin_bonus.c \
            ./checker/parser/ft_strlen_bonus.c \
            ./checker/parser/ft_substr_bonus.c \
            ./checker/parser/ft_validate_bonus.c \
            ./checker/parser/ft_validate_args_bonus.c \
            ./checker/parser/ft_word_count_bonus.c \
            ./checker/parser/parser_bonus.c \
            ./checker/stack/moves/push_bonus.c \
            ./checker/stack/moves/reverse_rotate_bonus.c \
            ./checker/stack/moves/rotate_bonus.c \
            ./checker/stack/moves/swap_bonus.c \
            ./checker/stack/utils/add_back_bonus.c \
            ./checker/stack/utils/clear_list_bonus.c \
            ./checker/stack/utils/create_item_bonus.c \
            ./checker/stack/utils/find_max_by_index_bonus.c \
            ./checker/stack/utils/find_min_by_index_bonus.c \
            ./checker/stack/utils/list_size_bonus.c

SRC_COMMON = ./push_swap.c \
            ./lib/error/error.c \
            ./lib/parser/ft_atol.c \
            ./lib/parser/ft_free_split.c \
            ./lib/parser/ft_holy_joint.c \
            ./lib/parser/ft_int_to_stack.c \
            ./lib/parser/ft_split.c \
            ./lib/parser/ft_str_to_int.c \
            ./lib/parser/ft_strdup.c \
            ./lib/parser/ft_strjoin.c \
            ./lib/parser/ft_strlen.c \
            ./lib/parser/ft_substr.c \
            ./lib/parser/ft_validate.c \
            ./lib/parser/ft_validate_args.c \
            ./lib/parser/ft_word_count.c \
            ./lib/parser/pa
            ./lib/sort/has_nums_in_range.c \
            ./lib/sort/is_sorted.c \
            ./lib/sort/push_back_to_a.c \
            ./lib/sort/push_to_b.c \
            ./lib/sort/sort.c \
            ./lib/stack/moves/push.c \
            ./lib/stack/moves/reverse_rotate.c \
            ./lib/stack/moves/rotate.c \
            ./lib/stack/moves/swap.c \
            ./lib/stack/utils/add_back.c \
            ./lib/stack/utils/clear_list.c \
            ./lib/stack/utils/create_item.c \
            ./lib/stack/utils/find_max_by_index.c \
            ./lib/stack/utils/find_min_by_index.c \
            ./lib/stack/utils/list_size.c 

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

INCLUDE = ./include

NAME = push_swap

NAME_CHECKER = checker

RM = rm -rf

all: $(NAME)

bonus : $(NAME_CHECKER)
.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ_COMMON)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJ_COMMON)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME) $(RED)BY 7ARZAN ..."
	@echo "$(GREEN)HAK HAHOWA $(YELLOW)$(NAME) $(GREEN)M9AD  ✔️"

$(NAME_CHECKER): $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJ_CHECKER)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME_CHECKER) $(RED)BY 7ARZAN ..."
	@echo "$(GREEN)HAK HAHOWA $(YELLOW)$(NAME_CHECKER) $(GREEN)M9AD  ✔️"

clean:
	@$(RM) $(OBJ_CHECKER) $(OBJ_COMMON)

fclean: clean
	@$(RM) $(NAME) $(NAME_CHECKER)
	@echo "$(RED)7ARZAN $(CYAN)GALIK MSA7 $(GREEN)L7ZA9 ✔️"

re : fclean all