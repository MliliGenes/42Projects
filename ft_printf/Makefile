SRC = src/init/init_functions.c \
    src/init/free_list.c \
    src/linked_list/new_node.c \
    src/linked_list/add_back.c \
    src/functions/put_char.c \
    src/functions/put_char_func.c \
    src/functions/put_str_func.c \
    src/functions/putnbr_func.c \
    src/functions/putunsigned_func.c \
    src/functions/puthex_lower_func.c \
    src/functions/puthex_upper_func.c \
    src/functions/putpointer_func.c \
    src/utils/putnbr_rec_func.c \
    src/utils/puthex_rec_func.c \
    src/utils/putpointer_rec_func.c \
	src/ft_printf.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c ./include/ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re