CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

INCLUDE_DIR = include
LIB_DIR = lib
PARSER_DIR = $(LIB_DIR)/parser
STACK_DIR = $(LIB_DIR)/stack
MOVES_DIR = $(STACK_DIR)/moves
UTILS_DIR = $(STACK_DIR)/utils
BUILD_DIR = build

SRC_MAIN = main.c
SRC_PARSER = $(PARSER_DIR)/ft_atol.c \
             $(PARSER_DIR)/ft_free_split.c \
             $(PARSER_DIR)/ft_holy_joint.c \
             $(PARSER_DIR)/ft_split.c \
             $(PARSER_DIR)/ft_str_to_int.c \
             $(PARSER_DIR)/ft_strdup.c \
             $(PARSER_DIR)/ft_strjoin.c \
             $(PARSER_DIR)/ft_strlen.c \
             $(PARSER_DIR)/ft_substr.c \
             $(PARSER_DIR)/ft_validate.c \
             $(PARSER_DIR)/ft_validate_args.c \
             $(PARSER_DIR)/ft_word_count.c \
             $(PARSER_DIR)/parser.c
SRC_MOVES = $(MOVES_DIR)/push.c \
            $(MOVES_DIR)/rotate.c \
            $(MOVES_DIR)/reverse_rotate.c \
            $(MOVES_DIR)/swap.c
SRC_UTILS = $(UTILS_DIR)/add_to_end.c \
            $(UTILS_DIR)/creat_item.c

SRC = $(SRC_MAIN) $(SRC_PARSER) $(SRC_MOVES) $(SRC_UTILS)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJ) -o $(NAME)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@) # Create necessary subdirectories
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
