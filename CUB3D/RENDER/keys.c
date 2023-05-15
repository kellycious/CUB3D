#include "../LIB/cub3d.h"

void	key_press(mlx_key_data_t key, void *param)
{
	t_map	*game;

	game = (t_map *) param;
	if (key.key == MLX_KEY_W
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		move_forward(data);
	if (key.key == MLX_KEY_S
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		move_backward(data);
	if (key.key == MLX_KEY_A
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		move_left(data);
	if (key.key == MLX_KEY_D
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		move_right(data);
	if (key.key == MLX_KEY_ESCAPE
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		return (exit_game(game));
}