# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:57:41 by sel-mlil          #+#    #+#              #
#    Updated: 2025/02/17 18:42:10 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_DIR = src
INCLUDE_DIR = ../includes/pipex.h

SRC_FILES = ../pipex.c $(SRC_DIR)/cleaning.c $(SRC_DIR)/commands.c \
			$(SRC_DIR)/parser.c $(SRC_DIR)/pipex_utils.c $(SRC_DIR)/quotes.c \
			$(SRC_DIR)/split.c $(SRC_DIR)/string.c $(SRC_DIR)/tokenizer.c

NAME = ../pipex 

OBJ_FILES = $(SRC_FILES:.c=.o)

$(NAME): $(OBJ_FILES) $(INCLUDE_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re