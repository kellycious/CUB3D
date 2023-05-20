#include "../LIB/cub3d.h"

int	game_init(t_map *game)
{
	game->mlx = mlx_init(800, 600, "cubi3d", 0);
	if (!game->mlx)
		return (ft_cleaner(game, "mlx_init failed\n"), 0);
	mlx_key_hook(game->mlx, key_press, (void *)game);
	mlx_close_hook(game->mlx, (void *) exit_game, (void *)game);
	texture_init(game);
	game->image = mlx_new_image(game->mlx, 800, 599);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	backgrounder(game);
	player_init(game, p_position(game));
	game->map[game->player_x][game->player_y] = '0';
	raycaster(game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->image);
	mlx_terminate(game->mlx);
	return (0);
}

void	backgrounder(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 599 / 2)
	{
		j = -1;
		while (++j < 800)
			mlx_pixel_put(game->mlx, j, i, 
				rgb_int(game->ceiling_r, game->ceiling_g, 
				game->ceiling_b, 0xff));
		i++;
	}
	while (i < 599)
	{
		j = -1;
		while (++j < 800)
			mlx_pixel_put(game->mlx, j, i, 
				rgb_int(game->floor_r, game->floor_g, 
				game->floor_b, 0xff));
		i++;
	}
}