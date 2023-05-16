#include "../LIB/cub3d.h"

int	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (0);
}

int	render_map(t_map *game)
{
	init_mlx(game);
	mlx_get_screen_size(game->mlx, &game->width, &game->height);
	texture_img(game);
	game->img = mlx_new_image(game->mlx, 800, 600);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line, 
		&game->endian);
	game->win = mlx_new_window(game->mlx, 800, 600, "CUB3D");
	game->imgbis = mlx_new_image(game->mlx, 800, 600);
	game->addrbis = mlx_get_data_addr(game->imgbis, &game->bpp, &game->line, 
		&game->endian);
	
	mlx_hook(recup->data.mlx_win, 33, 1L << 17, ft_exit, game);
	mlx_hook(recup->data.mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_loop_hook(recup->data.mlx_ptr, looper, game);
	mlx_hook(recup->data.mlx_win, 3, 1L << 1, ft_key_release, game);
	mlx_loop(game->mlx);
	return (0);
}

void	texture_pix(t_map *game)
{
	if (!(game->txt[NORTH].addr = (int *)mlx_get_data_addr(game->txt[NORTH].img, 
		&game->txt[NORTH].bpp, &game->txt[NORTH].line, 
		&game->txt[NORTH].endian)))
		return (ft_cleaner(game, "Error: xpm img NORTH\n"));
	if(!(game->txt[SOUTH].addr = (int *)mlx_get_data_addr(game->txt[SOUTH].img,
		&game->txt[SOUTH].bpp, &game->txt[SOUTH].line, 
		&game->txt[SOUTH].endian)))
		return (ft_cleaner(game, "Error: xpm img SOUTH\n"));
	if(!(game->txt[WEST].addr = (int *)mlx_get_data_addr(game->txt[WEST].img,
		&game->txt[WEST].bpp, &game->txt[WEST].line, 
		&game->txt[WEST].endian)))
		return (ft_cleaner(game, "Error: xpm img WEST\n"));
	if (!(game->txt[EAST].addr = (int *)mlx_get_data_addr(game->txt[EAST].img,
		&game->txt[EAST].bpp, &game->txt[EAST].line, 
		&game->txt[EAST].endian)))
		return (ft_cleaner(game, "Error: xpm img EAST\n"));
}
void	texture_img(t_map *game)
{
	game->txt[NORTH].img = mlx_xpm_file_to_image(game->mlx,game->no, 
		800, 600);
	game->txt[SOUTH].img = mlx_xpm_file_to_image(game->mlx, game->so, 
		800, 600);
	game->txt[WEST].img = mlx_xpm_file_to_image(game->mlx, game->we, 
		800, 600);
	game->txt[EAST].img = mlx_xpm_file_to_image(game->mlx, game->eq, 
		800, 600);
	texture_pix(game);
}

int		raycaster(t_map *game, t_rayc *ray)
{
	ray->x = 0;
	while (ray->x < game->width)
	{
		ft_init_ray(game, ray);
		
	}
}
