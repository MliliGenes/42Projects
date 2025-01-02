CC = gcc
CFLAGS = -Wall -Wextra -Werror
# INCLUDE = ./include/push_swap.h

SRC_DIR = lib
SRC_FILES = \
    $(SRC_DIR)/parser/ft_atol.c \
    $(SRC_DIR)/parser/ft_holy_joint.c \
    $(SRC_DIR)/parser/ft_split.c \
    $(SRC_DIR)/parser/ft_str_to_int.c \
    $(SRC_DIR)/parser/ft_strdup.c \
    $(SRC_DIR)/parser/ft_strjoin.c \
    $(SRC_DIR)/parser/ft_substr.c \
    $(SRC_DIR)/parser/ft_strlen.c \
    $(SRC_DIR)/parser/ft_validate.c \
    $(SRC_DIR)/parser/ft_validate_args.c \
    $(SRC_DIR)/parser/ft_word_count.c \
    $(SRC_DIR)/parser/ft_free_split.c \
    $(SRC_DIR)/stack/moves/push.c \
    $(SRC_DIR)/stack/moves/rotate.c \
    $(SRC_DIR)/stack/moves/swap.c \
    $(SRC_DIR)/stack/utils/add_to_end.c \
    $(SRC_DIR)/stack/utils/creat_item.c \
    main.c

OBJ_DIR = build
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
