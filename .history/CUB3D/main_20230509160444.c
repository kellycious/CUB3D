#include "LIB/cub3d.h"

int	main()
{
	t_map map;
	t_elements elements;

	char *argv = "MAPS/test.cub";
	// map = malloc(sizeof(t_map));
	// elements = malloc(sizeof(t_elements));

	ft_parsing(&map, elements, argv);
	// else
	// 	ft_putstr_fd("ERROR: invalid nb of arg\n", 2);
	return (0);
}
