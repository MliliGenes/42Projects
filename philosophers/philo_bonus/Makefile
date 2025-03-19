# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 01:48:10 by sel-mlil          #+#    #+#              #
#    Updated: 2025/03/19 05:44:52 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror 

SRC_DIR = src
HEADER_FILE = include/philo_bonus.h

SRCS = main_bonus.c \
	$(SRC_DIR)/getters_setters_bonus.c \
	$(SRC_DIR)/lib_bonus.c \
	$(SRC_DIR)/parsing_utils_bonus.c \
	$(SRC_DIR)/philos_utils_bonus.c \
	$(SRC_DIR)/simualtion_utils_bonus.c \
    $(SRC_DIR)/time_utils_bonus.c \
    $(SRC_DIR)/global_monitor_bonus.c

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re