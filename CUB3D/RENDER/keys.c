#include "../LIB/cub3d.h"

int	key_press(int keycode, t_map *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119)
		game->player->forward = 1;
	if (keycode == 115)
		game->player->backward = 1;
	if (keycode == 97)
		game->player->left = 1;
	if (keycode == 100)
		game->player->right = 1;
	return (0);
}

int	key_release(int keycode, t_map *game)
{
	if (keycode == 119)
		game->player->forward = 0;
	if (keycode == 115)
		game->player->backward = 0;
	if (keycode == 97)
		game->player->left = 0;
	if (keycode == 100)
		game->player->right = 0;
	return (1);
}