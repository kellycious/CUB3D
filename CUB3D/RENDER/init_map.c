#include "../LIB/cub3d.h"

int	init_mlx(t_mlxy *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (init_img(map));
}

int	init_img(t_mlxy *map)
{
	map->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!map->img)
	
}