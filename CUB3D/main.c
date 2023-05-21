#include "LIB/cub3d.h"

int	main(int ac, char **av)
{
	t_map *map;
	t_elements *elements;
	t_mlx *mlxy;
	int i = 0;
	(void)av;

	ac = 2;
	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	while (i < 4)
	{
		mlxy = ft_calloc(sizeof(t_mlx), 1);
		map->txt[i] = mlxy;
		i++;
	}
	ft_parsing(map, elements, ac, "MAPS/test.cub");
	render_map(map);
	exit_game(map);
	return (0);
}
