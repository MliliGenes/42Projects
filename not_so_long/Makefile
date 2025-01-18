# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 03:43:17 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/18 18:25:35 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g

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
			src/lib/get_next_line.c \
			src/lib/is_map_enclosed.c \
			src/lib/list_len.c \
			src/lib/list_t_dup.c \
			src/lib/search_in_map.c \
			src/lib/ft_calloc.c \
			src/error/error.c \
			src/game/init_game.c \
			src/game/init_texture.c \
			src/game/init_map.c \
			src/game/draw_map.c \
			src/game/draw_player.c \
			src/game/put_image.c \
			src/game/init_player.c \
			src/game/event_lister.c \
			src/game/convert_map.c \
			src/game/expand_map.c \
			src/game/free_expended_map.c \
			src/game.c

SRC_CHECKER = ""

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_BONUS = $(SRC_CHECKER:.c=.o)

INCLUDE = -I./includes

NAME = so_long

NAME_BONUS = so_long_fr

LIBMLX = libmlx42.a

LIBS = -lglfw -L"/goinfre/sel-mlil/homebrew/opt/glfw/lib"

RM = rm -f

all: $(NAME)

bonus : $(NAME_BONU)

$(NAME): $(OBJ_COMMON)
	$(CC) $(CFLAGS) $(OBJ_COMMON) $(LIBMLX) $(INCLUDE) $(LIBS) -o $(NAME)

$(NAME_BONU): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME_BONUS) $(OBJ_CHECKER)
	
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_CHECKER) $(OBJ_COMMON)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

# 111111111111111111111111111111
# 1C00000001111011111100000000C1
# 1011111101000000000101111110C1
# 10P0000001111101111100000000C1
# 1011111100000000000001111110C1
# 1E00C0000111110111110000000001
# 1011111100000000000001111110C1
# 1000000001111101111100000000C1
# 1011111101000000000101111110C1
# 1C00000001111101111100000000C1
# 111111111111111111111111111111
