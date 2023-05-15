#include "../LIB/cub3d.h"

void	key_press(mlx_key_data_t key, void *param)
{
	t_map	*game;

	game = (t_map *) param;
	if (key.key == MLX_KEY_W
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		forward(data);
	if (key.key == MLX_KEY_S
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		backward(data);
	if (key.key == MLX_KEY_A
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		left(data);
	if (key.key == MLX_KEY_D
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		right(data);
	if (key.key == MLX_KEY_ESCAPE
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		return (exit_game(game));
}

void	forward(t_map *game)
{
	
}
void	backward(t_map *game)
void	left(t_map *game)
void	right(t_map *game)