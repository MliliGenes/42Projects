# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mlil           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 03:43:17 by sel-mlil          #+#    #+#              #
#    Updated: 2025/01/26 18:09:46 by sel-mlil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR = ./all
BONUS_DIR = ./bonus

SWITCH_FILES = src/game/update_player.o \
			src/game/event_lister.o \
			src/game.o \
			src/parser.o 

all:
	$(if $(wildcard .bonus),rm -f $(SWITCH_FILES) .bonus)
	@$(MAKE) -C $(MANDATORY_DIR)

bonus:
	$(if $(wildcard .bonus),,rm -f $(SWITCH_FILES))
	@$(MAKE) -C $(BONUS_DIR)
	touch .bonus

clean:
	@$(MAKE) -C $(MANDATORY_DIR) clean
	@$(MAKE) -C $(BONUS_DIR) clean

fclean:
	@$(MAKE) -C $(MANDATORY_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

switch :
	rm -f $(SWITCH_FILES)

.PHONY : bonus re fclean clean all