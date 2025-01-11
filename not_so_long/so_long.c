#include "includes/lib.h"

// get_next_line

// add file to fd function

// read and push to **map

int	main(int argc, char **argv)
{
	char	*path;
	char	*prefix;
	list_t	*map;

	prefix = ft_strdup("./maps/map.ber");
	path = ft_strjoin(prefix, argv[1]);

    map = NULL;
    if (!parser(path, &map))
        return (EXIT_FAILURE);
}
