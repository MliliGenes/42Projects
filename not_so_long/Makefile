# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 03:43:17 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/25 20:43:54 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g # -O3

SRC_COMMON = so_long.c src/parser.c \
			src/lib/add_back_list_t.c \
			src/lib/clear_list_t_list.c \
			src/lib/create_list_t_node.c \
			src/lib/create_map.c \
			src/lib/file_to_fd.c \
			src/lib/find_pos_in_map.c \
			src/lib/flood_fill_validate.c \
			src/lib/ft_strchr.c \
			src/lib/ft_strdup.c \
			src/lib/ft_strjoin.c \
			src/lib/ft_strlen.c \
			src/lib/ft_putnbr.c \
			src/lib/get_next_line.c \
			src/lib/is_map_enclosed.c \
			src/lib/list_len.c \
			src/lib/list_t_dup.c \
			src/lib/search_in_map.c \
			src/lib/ft_calloc.c \
			src/error/error.c \
			src/game/init_game.c \
			src/game/init_texture.c \
			src/game/init_animations.c \
			src/game/init_map.c \
			src/game/draw_map.c \
			src/game/draw_player.c \
			src/game/draw_exit.c \
			src/game/draw_coins.c \
			src/game/put_image.c \
			src/game/init_player.c \
			src/game/print_moves.c \
			src/game/update_player.c \
			src/game/event_lister.c \
			src/game/collision.c \
			src/game/check_exit.c \
			src/game/convert_map.c \
			src/game/expand_map.c \
			src/game/clean_exit.c \
			src/game/exit_game.c \
			src/game/free_expended_map.c \
			src/game.c

SRC_BONUS = $(SRC_COMMON) \

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDE = -I./includes

HEADER_FILES = ./includes/structs.h \
				./includes/game.h \
				./includes/lib.h \
				./includes/so_long.h 

NAME = so_long

NAME_BONUS = so_long_fr

LIBMLX = libmlx42.a

LIBS = -lglfw -L"/goinfre/sel-mlil/homebrew/opt/glfw/lib"

RM = rm -f

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ_COMMON) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJ_COMMON) $(INCLUDE) $(LIBMLX) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDE) $(LIBMLX) $(LIBS) -DANIMATE=true -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_BONUS) $(OBJ_COMMON)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

