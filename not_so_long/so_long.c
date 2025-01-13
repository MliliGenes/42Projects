#include "includes/lib.h"

int	main(int argc, char **argv)
{
	list_t	*map;
	char	*message;

	(void)argc;
	message = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (!parser(argv[1], &map))
	{
		error(message);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
