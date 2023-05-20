#include "LIB/cub3d.h"

int	main()
{
	t_map *map;
	t_elements *elements;

	char *argv = "MAPS/test.cub";
	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	ft_parsing(map, elements, argv);
	render_map(map);
	exit_game(map);
	return (0);
}
