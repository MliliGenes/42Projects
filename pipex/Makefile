all:
	@$(MAKE) -C bonus clean
	@$(MAKE) -C mandatory

bonus:
	@$(MAKE) -C mandatory clean
	@$(MAKE) -C bonus

clean:
	@$(MAKE) -C mandatory clean
	@$(MAKE) -C bonus clean

fclean:
	@$(MAKE) -C mandatory fclean
	@$(MAKE) -C bonus fclean

re: fclean all

.PHONY: all clean fclean re bonus