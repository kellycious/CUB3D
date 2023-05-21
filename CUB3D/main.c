#include "LIB/cub3d.h"

int	main(int ac, char **av)
{
	t_map *map;
	t_elements *elements;
	t_mlx *mlxy;
	t_rayc *ray;
	t_player *player;
	t_texture *texture;
	t_coor *coor;
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
	ray = ft_calloc(sizeof(t_rayc), 1);
	map->ray = ray;
	i = -1;
	while (++i < 6)
		coor = ft_calloc(sizeof(t_coor), 1);
	map->ray->dir = coor[0];
	map->ray->step = coor[1];
	map->ray->length = coor[2];
	map->ray->gline = coor[3];
	map->ray->unit = coor[4];
	map->ray->start = coor[5];
	player = ft_calloc(sizeof(t_player), 1);
	map->player = player;
	texture = ft_calloc(sizeof(t_texture), 1);
	map->tex = texture;
	ft_parsing(map, elements, ac, "MAPS/test.cub");
	render_map(map);
	exit_game(map);
	return (0);
}
