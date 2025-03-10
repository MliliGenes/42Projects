# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 01:48:10 by sel-mlil          #+#    #+#              #
#    Updated: 2025/03/10 02:02:35 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_DIR = src
INCLUDE_DIR = include

SRCS = main.c \
       $(SRC_DIR)/getters_setters.c \
       $(SRC_DIR)/lib.c \
       $(SRC_DIR)/parsing_utils.c \
       $(SRC_DIR)/philos_utils.c \
       $(SRC_DIR)/simualtion_utils.c \
       $(SRC_DIR)/time_utils.c

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re