# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by sel-mlil          #+#    #+#              #
#    Updated: 2025/07/08 18:46:19 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================== CONFIG ================================== #

NAME        = cub3d
BONUS       = cub3d_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
LDFLAGS     = 
INCLUDES    = -I"mandatory/include"
BONUS_INCLUDES = -I"bonus/include"

# MLX Configuration
MLX_LIBRARIES = -L"/Users/sel-mlil/goinfre/homebrew/opt/glfw/lib" -lglfw \
		../mlx/libmlx42.a \
		-framework Cocoa -framework OpenGL -framework IOKit -lm -ldl

# For Linux (commented out)
# MLX_LIBRARIES = ../mlx/libmlx42_linux.a -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lm -ldl

# ================================== COLORS ================================== #

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m
BOLD        = \033[1m
RESET       = \033[0m

# ================================== SOURCES ================================= #

# Header files
MANDATORY_HEADERS = mandatory/include/cub3d.h \
	    mandatory/include/dependencies.h \
	    mandatory/include/init.h \
	    mandatory/include/lib.h \
	    mandatory/include/parsing.h \
	    mandatory/include/structs.h \
	    mandatory/include/game.h \
	    ../mlx/MLX42.h

BONUS_HEADERS = bonus/include/cub3d_bonus.h \
	    bonus/include/dependencies_bonus.h \
	    bonus/include/init_bonus.h \
	    bonus/include/lib_bonus.h \
	    bonus/include/parsing_bonus.h \
	    bonus/include/structs_bonus.h \
	    bonus/include/game_bonus.h \
	    ../mlx/MLX42.h

# Source files organized by directory
MAIN_SRC = main.c \
	   cleanup.c

EVENT_SRC = event_listner/event_listner.c \
	    event_listner/game_loop.c

INIT_SRC = init/init_game.c \
	   init/init_player.c \
	   init/init_rays.c \
	   init/init_textures.c \
	   init/init_textures_utils.c \
	   init/init_walls.c

LIB_SRC = lib/deg_to_rad.c \
	  lib/normalize_angle.c \
	  lib/pixel.c \
	  lib/ft_memset.c

PLAYER_SRC = player/player.c \
	     player/open_door.c \
	     player/mouse_handle.c

RAYCAST_SRC = raycaster/build_walls.c \
	      raycaster/ray_caster.c \
	      raycaster/dda_utils.c \
	      raycaster/floor_cell.c \
	      raycaster/rays_to_walls.c

PARSING_SRC = parsing/file_check.c \
	      parsing/checkinox.c \
	      parsing/check_2.c \
	      parsing/gnl.c \
	      parsing/gnl_utils.c \
	      parsing/parse_map.c \
	      parsing/split.c \
	      parsing/utils.c \
	      parsing/parse_map_2.c \
	      parsing/parse_map_utils_3.c \
	      parsing/utils2.c \
	      parsing/utils3.c \
	      parsing/utils4.c \
	      parsing/utils5.c \
	      parsing/parse_map_utils.c \
	      parsing/ft_freeing_free.c \
	      parsing/parse_map_utils_2.c

MINIMAP_SRC = map/minimap_utils.c \
	      map/minimap.c

# Combined source files
SRC = $(MAIN_SRC) $(EVENT_SRC) $(INIT_SRC) $(LIB_SRC) $(PLAYER_SRC) \
      $(RAYCAST_SRC) $(PARSING_SRC) $(MINIMAP_SRC)

# Object files
SRC_MANDATORY = $(addprefix mandatory/, $(SRC))
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

SRC_BONUS = $(patsubst %.c, %_bonus.c, $(addprefix bonus/, $(SRC)))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# ================================== RULES =================================== #

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ_MANDATORY)
	@echo "$(CYAN)$(BOLD)Linking $(NAME)...$(RESET)"
	@$(CC) $(LDFLAGS) $(OBJ_MANDATORY) $(MLX_LIBRARIES) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) created successfully!$(RESET)\n"

$(BONUS): $(OBJ_BONUS)
	@echo "$(CYAN)$(BOLD)Linking $(BONUS)...$(RESET)"
	@$(CC) $(LDFLAGS) $(OBJ_BONUS) $(MLX_LIBRARIES) -o $(BONUS)
	@echo "$(GREEN)$(BOLD)✓ $(BONUS) created successfully!$(RESET)\n"

# Compilation rules
mandatory/%.o: mandatory/%.c $(MANDATORY_HEADERS)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(RESET)"
	@$(CC) $(CFLAGS) -I"./mandatory/include/" -c $< -o $@

bonus/%_bonus.o: bonus/%_bonus.c $(BONUS_HEADERS)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(RESET)"
	@$(CC) $(CFLAGS) -I"./bonus/include/" -c $< -o $@

# ================================== CLEAN =================================== #

clean:
	@echo "$(RED)$(BOLD)Cleaning object files...$(RESET)"
	@rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Cleaning executables...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@echo "$(GREEN)✓ Everything cleaned!$(RESET)"

re: fclean all

re_bonus: fclean bonus

# ================================ UTILITIES ================================= #

run: $(NAME)
	@echo "$(MAGENTA)$(BOLD)Running $(NAME)...$(RESET)"
	@./$(NAME) levels/map.cub

run_bonus: $(BONUS)
	@echo "$(MAGENTA)$(BOLD)Running $(BONUS)...$(RESET)"
	@./$(BONUS) levels/map.cub

debug: CFLAGS += -g3 -fsanitize=address
debug: LDFLAGS += -g3 -fsanitize=address
debug: fclean $(NAME)
	@echo "$(BLUE)$(BOLD)✓ Debug build created!$(RESET)"

debug_bonus: CFLAGS += -g3 -fsanitize=address
debug_bonus: LDFLAGS += -g3 -fsanitize=address
debug_bonus: fclean $(BONUS)
	@echo "$(BLUE)$(BOLD)✓ Debug bonus build created!$(RESET)"

leak: CFLAGS += -g3
leak: LDFLAGS += -g3
leak: fclean $(NAME)
	@echo "$(BLUE)$(BOLD)✓ Leak check build created!$(RESET)"
	@echo "$(YELLOW)Run with: leaks --atExit -- ./$(NAME) levels/map.cub$(RESET)"

# ================================== INFO ==================================== #

help:
	@echo "$(CYAN)$(BOLD)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)          - Build the mandatory program"
	@echo "  $(GREEN)bonus$(RESET)        - Build the bonus program"
	@echo "  $(GREEN)clean$(RESET)        - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)       - Remove object files and executables"
	@echo "  $(GREEN)re$(RESET)           - Rebuild mandatory program"
	@echo "  $(GREEN)re_bonus$(RESET)     - Rebuild bonus program"
	@echo "  $(GREEN)run$(RESET)          - Build and run mandatory program"
	@echo "  $(GREEN)run_bonus$(RESET)    - Build and run bonus program"
	@echo "  $(GREEN)debug$(RESET)        - Build with debug flags (AddressSanitizer)"
	@echo "  $(GREEN)debug_bonus$(RESET)  - Build bonus with debug flags"
	@echo "  $(GREEN)leak$(RESET)         - Build for leak checking"
	@echo "  $(GREEN)show$(RESET)         - Show project structure"
	@echo "  $(GREEN)help$(RESET)         - Show this help message"

show:
	@echo "$(CYAN)$(BOLD)Project Structure:$(RESET)"
	@echo "$(YELLOW)Mandatory executable:$(RESET) $(NAME)"
	@echo "$(YELLOW)Bonus executable:$(RESET) $(BONUS)"
	@echo "$(YELLOW)Source files ($(words $(SRC)) files):$(RESET)"
	@for file in $(SRC); do echo "  $(WHITE)•$(RESET) $$file"; done
	@echo "$(YELLOW)Mandatory objects ($(words $(OBJ_MANDATORY)) files):$(RESET)"
	@for file in $(OBJ_MANDATORY); do echo "  $(WHITE)•$(RESET) $$file"; done
	@echo "$(YELLOW)Bonus objects ($(words $(OBJ_BONUS)) files):$(RESET)"
	@for file in $(OBJ_BONUS); do echo "  $(WHITE)•$(RESET) $$file"; done

status:
	@echo "$(CYAN)$(BOLD)Build Status:$(RESET)"
	@if [ -f $(NAME) ]; then echo "$(GREEN)✓ $(NAME) exists$(RESET)"; else echo "$(RED)✗ $(NAME) missing$(RESET)"; fi
	@if [ -f $(BONUS) ]; then echo "$(GREEN)✓ $(BONUS) exists$(RESET)"; else echo "$(RED)✗ $(BONUS) missing$(RESET)"; fi
	@echo "$(YELLOW)Object files:$(RESET)"
	@echo "  Mandatory: $(shell find mandatory -name '*.o' 2>/dev/null | wc -l | tr -d ' ')/$(words $(OBJ_MANDATORY))"
	@echo "  Bonus: $(shell find bonus -name '*.o' 2>/dev/null | wc -l | tr -d ' ')/$(words $(OBJ_BONUS))"

# ================================== PHONY =================================== #

.PHONY: all bonus clean fclean re re_bonus run run_bonus debug debug_bonus \
	leak help show status