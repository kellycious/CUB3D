#include "LIB/cub3d.h"

int	main()
{
	t_map *map;
	t_elements *elements;

	char *argv = "MAPS/test.cub";
	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	elements->map = map;
	map->elements = elements;

	ft_parsing(map, elements, argv);
	free(map->elements);
	// else
	// 	ft_putstr_fd("ERROR: invalid nb of arg\n", 2);
	return (0);
}
