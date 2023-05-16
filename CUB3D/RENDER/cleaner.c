#include "../LIB/cub3d.h"

void	exit_game(t_map *game)
{
	mlx_terminate(game->mlx);
	ft_cleaner(game, NULL);
}