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