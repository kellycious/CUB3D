#include "../LIB/cub3d.h"

int	key_press(int keycode, t_map *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119)
		game->mlx->forward = 1;
	if (keycode == 115)
		game->mlx->backward = 1;
	if (keycode == 97)
		game->mlx->left = 1;
	if (keycode == 100)
		game->mlx->right = 1;
	return (0);
}

int	key_release(int keycode, t_map *game)
{
	if (keycode == 119)
		game->mlx->forward = 0;
	if (keycode == 115)
		game->mlx->backward = 0;
	if (keycode == 97)
		game->mlx->left = 0;
	if (keycode == 100)
		game->mlx->right = 0;
	return (1);
}