#include "../LIB/cub3d.h"

static int	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (0);
}

int	render_map(t_map *game)
{
	init_mlx(game);
//	mlx_get_screen_size(game->mlx, &game->widthy, &game->heighty);
	game->img = mlx_new_image(game->mlx, game->widthy, game->heighty);
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp, &game->line,
			&game->endian);
	game->win = mlx_new_window(game->mlx, game->widthy, game->heighty, "CUB3D");
	texture_img(game);
	game->imgbis = mlx_new_image(game->mlx, game->widthy, game->heighty);
	game->addrbis = (int *)mlx_get_data_addr(game->imgbis, &game->bpp,
			&game->line, &game->endian);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 33, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, raycaster, game);
	mlx_loop(game->mlx);
	return (0);
}
