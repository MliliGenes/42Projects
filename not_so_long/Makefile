# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 03:43:17 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/12 03:46:09 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_COMMON = ""

SRC_CHECKER = ""

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

INCLUDE = ./includes

NAME = so_long

NAME_BONU = so_long_fr

RM = rm -f

all: $(NAME)

bonus : $(NAME_BONU)

$(NAME): $(OBJ_COMMON)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJ_COMMON)

$(NAME_BONU): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME_BONUS) $(OBJ_CHECKER)
	
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_CHECKER) $(OBJ_COMMON)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all