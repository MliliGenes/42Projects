# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 18:31:11 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/30 23:22:30 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -DANIMATE=1 -fsanitize=address -g
SRC = ../src/parser.c \
			../src/lib/add_back_list_t.c \
			../src/lib/clear_list_t_list.c \
			../src/lib/create_list_t_node.c \
			../src/lib/create_map.c \
			../src/lib/file_to_fd.c \
			../src/lib/find_pos_in_map.c \
			../src/lib/flood_fill_validate.c \
			../src/lib/ft_strchr.c \
			../src/lib/ft_strdup.c \
			../src/lib/ft_strjoin.c \
			../src/lib/ft_strlen.c \
			../src/lib/ft_putnbr.c \
			../src/lib/get_next_line.c \
			../src/lib/is_map_enclosed.c \
			../src/lib/list_len.c \
			../src/lib/list_t_dup.c \
			../src/lib/search_in_map.c \
			../src/lib/ft_calloc.c \
			../src/error/error.c \
			../src/game/init_game.c \
			../src/game/init_texture.c \
			../src/game/init_animations.c \
			../src/game/init_map.c \
			../src/game/spike_collision.c \
			../src/game/draw_map.c \
			../src/game/draw_player.c \
			../src/game/draw_exit.c \
			../src/game/draw_coins.c \
			../src/game/draw_spikes.c \
			../src/game/put_image.c \
			../src/game/init_player.c \
			../src/game/print_moves.c \
			../src/game/update_player.c \
			../src/game/update_spikes.c \
			../src/game/event_lister.c \
			../src/game/collision.c \
			../src/game/check_exit.c \
			../src/game/convert_map.c \
			../src/game/expand_map.c \
			../src/game/clean_exit.c \
			../src/game/ft_itoa.c \
			../src/game/print_moves_in_win.c \
			../src/game/exit_game.c \
			../src/game/free_expended_map.c \
			../src/game.c \
			../so_long.c
OBJ = $(SRC:.c=.o)
INCLUDE = -I../includes
HEADER_FILES = ../includes/structs.h \
				../includes/game.h \
				../includes/lib.h \
				../includes/so_long.h
NAME = ../so_long_fr
LIBMLX = ../libmlx42.a
LIBS = -lglfw -L"/goinfre/sel-mlil/homebrew/opt/glfw/lib"
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBMLX) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
