#include "LIB/cub3d.h"

int	main(int ac, char **av)
{
	t_map *map;
	t_elements *elements;
	(void)ac;

	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	ft_parsing(map, elements, ac, av[1]);
	//render_map(map);
	//exit_game(map);
	return (0);
}
