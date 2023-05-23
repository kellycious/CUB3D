#include "LIB/cub3d.h"

int	main(int ac, char **av)
{
	t_map *map;
	t_elements *elements;
	t_mlx *mlxy;
	t_rayc *ray;
	t_player *player;
	t_texture *texture;
	int i = 0;
	(void)av;

	ac = 2;
	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	while (i < 4)
	{
		mlxy = ft_calloc(sizeof(t_mlx), 1);
		map->txt[i] = *mlxy;
		i++;
	}
	ray = ft_calloc(sizeof(t_rayc), 1);
	map->ray = *ray;
	texture = ft_calloc(sizeof(t_texture), 1);
	map->tex = *texture;
	player = ft_calloc(sizeof(t_player), 1);
	map->player = player;
	ft_parsing(map, elements, ac, "MAPS/test.cub");
	render_map(map);
	exit_game(map);
	return (0);
}
