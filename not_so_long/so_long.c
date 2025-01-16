#include "includes/so_long.h"
#include "includes/game.h"

int	main(int argc, char **argv)
{
	game_t	*game;
	char	*message;

	message = NULL;
	game = init_game_struct();
	if (argc != 2)
		return (EXIT_FAILURE);
	if (!parser(argv[1], &(game->map->grid)))
		return (error(message), EXIT_FAILURE);
	return (EXIT_FAILURE);
}
