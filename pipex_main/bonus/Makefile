# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:57:41 by sel-mlil          #+#    #+#              #
#    Updated: 2025/02/16 07:05:55 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = ../includes/pipex_bonus.h

SRC_FILES = ../pipex_bonus.c $(SRC_DIR)/cleaning_bonus.c $(SRC_DIR)/commands_bonus.c \
			$(SRC_DIR)/parser_bonus.c $(SRC_DIR)/pipex_utils_bonus.c $(SRC_DIR)/quotes_bonus.c \
			$(SRC_DIR)/split_bonus.c $(SRC_DIR)/string_bonus.c $(SRC_DIR)/tokenizer_bonus.c \
			$(SRC_DIR)/heredoc_bonus.c $(SRC_DIR)/strcmp_bonus.c $(SRC_DIR)/get_next_line_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = ../pipex

$(NAME): $(OBJ_FILES) $(INCLUDE_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re