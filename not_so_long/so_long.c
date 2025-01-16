#include "includes/game.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*message;

	message = NULL;
	game = init_game_struct();
	if (argc != 2)
		return (EXIT_FAILURE);
	if (!parser(argv[1], &(game->map)))
		return (error(message), free(game), EXIT_FAILURE);
	if(!init_textures(&(game->assets)))
		return (error(message), free(game), EXIT_FAILURE);
	
	return (EXIT_FAILURE);
}
