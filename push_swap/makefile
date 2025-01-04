CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

INCLUDE_DIR = include
LIB_DIR = lib
PARSER_DIR = $(LIB_DIR)/parser
SORT_DIR = $(LIB_DIR)/sort
ERROR_DIR = $(LIB_DIR)/error
STACK_DIR = $(LIB_DIR)/stack
MOVES_DIR = $(STACK_DIR)/moves
UTILS_DIR = $(STACK_DIR)/utils
BUILD_DIR = build

SRC_MAIN = push_swap.c

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
             $(PARSER_DIR)/ft_int_to_stack.c \
             $(PARSER_DIR)/parser.c

SRC_MOVES = $(MOVES_DIR)/push.c \
            $(MOVES_DIR)/rotate.c \
            $(MOVES_DIR)/reverse_rotate.c \
            $(MOVES_DIR)/swap.c

SRC_UTILS = $(UTILS_DIR)/create_item.c \
            $(UTILS_DIR)/add_back.c \
            $(UTILS_DIR)/find_max_by_index.c \
            $(UTILS_DIR)/list_size.c \
            $(UTILS_DIR)/clear_list.c 

SRC_SORT = $(SORT_DIR)/sort.c \
            $(SORT_DIR)/push_to_b.c \
            $(SORT_DIR)/is_sorted.c \
            $(SORT_DIR)/has_nums_in_range.c \
            $(SORT_DIR)/push_back_to_a.c

SRC_ERROR = $(ERROR_DIR)/error.c

SRC = $(SRC_MAIN) $(SRC_PARSER) $(SRC_MOVES) $(SRC_UTILS) $(SRC_SORT) $(SRC_ERROR)

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
