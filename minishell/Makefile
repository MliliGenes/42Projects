CC = cc
ERRORS = -Wall -Wextra -Werror -O3
SANITIZER = -fsanitize=address -g3
CFLAGS = $(ERRORS) $(SANITIZER)
LIB = -L"/Users/sel-mlil/goinfre/homebrew/opt/readline/lib" -lreadline

NAME = minishell
NAME_BONUS = minishell_bonus

BUILD_DIR = build

MANDATORY_DIR = mandatory
BONUS_DIR = bonus
INCLUDE_DIR = include

MANDATORY_HEADERS = \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/builtins.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/dependencies.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/execution.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/lib.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/minishell.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/parsing.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/signals.h \
    $(MANDATORY_DIR)/$(INCLUDE_DIR)/structs.h

BONUS_HEADERS = \
    $(BONUS_DIR)/$(INCLUDE_DIR)/builtins_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/dependencies_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/execution_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/lib_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/minishell_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/parsing_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/signals_bonus.h \
    $(BONUS_DIR)/$(INCLUDE_DIR)/structs_bonus.h

SRC_FILES = main.c \
    signals.c \
    shell_loop.c \
    cleaning.c \
    lib/string_utils_1.c \
    lib/string_utils_2.c \
    lib/string_utils_3.c \
    lib/string_utils_4.c \
    lib/string_utils_5.c \
    lib/error_utils.c \
    tokenizer/token_classification.c \
    tokenizer/token_handling.c \
    tokenizer/token_utils.c \
    tokenizer/token_validation.c \
    tokenizer/token_checkers.c \
    tokenizer/tokenizer.c \
    processing/command_utils.c \
    processing/operator_utils.c \
    processing/processing.c \
    processing/processing_utils.c \
    processing/ready_token_utils.c \
    processing/redirection_utils.c \
    parsing/ast_construction.c \
    parsing/parser.c \
    parsing/parser_utils.c \
    parsing/shunting_yard.c \
    builtins/env_utils.c \
    builtins/ft_cd.c \
    builtins/cd_utils.c \
    builtins/ft_echo.c \
    builtins/ft_env.c \
    builtins/ft_exit.c \
    builtins/ft_export.c \
    builtins/export_utils.c \
    builtins/export_env.c \
    builtins/ft_pwd.c \
    builtins/ft_unset.c \
    builtins/builtins_utils.c \
    execution/env_utils.c \
    execution/execute_cmd_handle.c \
    execution/execute_cmd_utils.c \
    execution/redirections.c \
    execution/redir_utils.c \
    execution/pipe.c \
    execution/and_or.c \
    execution/readfile.c \
    post_processing/args_utils.c \
    post_processing/expention_utils.c \
    post_processing/expension.c \
    post_processing/join_args.c \
    post_processing/split_args.c \
    post_processing/remove_quotes.c \
    post_processing/update_cmd_node.c \
    post_processing/marking_utils.c \
    post_processing/entry.c \
    post_processing/entry_utils.c \
    post_processing/wildcard.c \
    post_processing/entry_operations.c \
    post_processing/expansion_wildcard.c \
    heredoc/open_here_docs.c \
    heredoc/here_doc_utils.c

SRC_FILES_MANDATORY = $(addprefix $(MANDATORY_DIR)/, $(SRC_FILES))
SRC_FILES_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_FILES:.c=_bonus.c))

OBJ_FILES = $(patsubst $(MANDATORY_DIR)/%.c, $(BUILD_DIR)/$(MANDATORY_DIR)/%.o, $(SRC_FILES_MANDATORY))
OBJ_FILES_BONUS = $(patsubst $(BONUS_DIR)/%_bonus.c, $(BUILD_DIR)/$(BONUS_DIR)/%.o, $(SRC_FILES_BONUS))

INC_FLAGS = -I$(MANDATORY_DIR)/$(INCLUDE_DIR) -I$(BONUS_DIR)/$(INCLUDE_DIR) -I"/Users/sel-mlil/goinfre/homebrew/opt/readline/include"

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RED     = \033[0;31m
RESET   = \033[0m

all: $(NAME)

bonus: $(NAME_BONUS)

run: re
	@printf "$(BLUE)🚀  Running minishell...$(RESET)\n"
	@./minishell

run_bonus: re_bonus
	@printf "$(BLUE)🚀  Running minishell bonus...$(RESET)\n"
	@./minishell_bonus

$(NAME): $(OBJ_FILES)
	@printf "$(YELLOW)🔨  Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(INC_FLAGS) $(LIB) -o $(NAME)
	@printf "$(GREEN)✅  Executable $(NAME) created$(RESET)\n"

$(NAME_BONUS): $(OBJ_FILES_BONUS)
	@printf "$(YELLOW)🔨  Linking bonus objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ_FILES_BONUS) $(INC_FLAGS) $(LIB) -o $(NAME_BONUS)
	@printf "$(GREEN)✅  Executable $(NAME_BONUS) created$(RESET)\n"

$(BUILD_DIR)/$(MANDATORY_DIR)/%.o: $(MANDATORY_DIR)/%.c $(MANDATORY_HEADERS)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)🔧  Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(MANDATORY_DIR)/$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/$(BONUS_DIR)/%.o: $(BONUS_DIR)/%_bonus.c $(BONUS_HEADERS)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)🔧  Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(BONUS_DIR)/$(INCLUDE_DIR) -c $< -o $@

clean:
	@printf "$(RED)🧹  Cleaning object files...$(RESET)\n"
	@rm -rf $(BUILD_DIR)/$(MANDATORY_DIR)

clean_bonus:
	@printf "$(RED)🧹  Cleaning bonus object files...$(RESET)\n"
	@rm -rf $(BUILD_DIR)/$(BONUS_DIR)

fclean: clean clean_bonus
	@printf "$(RED)🧹  Removing executables...$(RESET)\n"
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean clean_bonus fclean re re_bonus run run_bonus