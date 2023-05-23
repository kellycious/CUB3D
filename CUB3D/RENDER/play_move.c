#include "../LIB/cub3d.h"

void	forward(t_map *game)
{
	if (game->player->forward == 1)
	{
	if (game->map[(int)((game->ray.px + (game->ray.dirx
				* 0.3)))][(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.dirx * 0.3;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				+ (game->ray.diry * 0.3))] == '0')
		game->ray.py += game->ray.diry * 0.3;
	}
}

void	backward(t_map *game)
{
	if (game->player->backward == 1)
	{
		if (game->map[(int)((game->ray.px) - (game->ray.dirx
					* 0.3 * 2))][(int)(game->ray.py)] == '0')
			game->ray.px -= game->ray.dirx * 0.3;
		if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
					- (game->ray.diry * 0.3 * 2))] == '0')
			game->ray.py -= game->ray.diry * 0.3;
	}
}

void	left(t_map *game)
{
	if (game->player->left == 1)
	{
		if (game->map[(int)((game->ray.px) + (game->ray.dirx
					* 0.3 * 2))][(int)(game->ray.py)] == '0')
			game->ray.px -= game->ray.diry * 0.3;
		if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				+ (game->ray.dirx * 0.3 * 2))] == '0')
			game->ray.py += game->ray.dirx * 0.3;
	}
}

void	right(t_map *game)
{
	if (game->player->right == 1)
	{
		if (game->map[(int)((game->ray.px) - (game->ray.diry
					* 0.3 * 2))][(int)(game->ray.py)] == '0')
			game->ray.py += game->ray.dirx* 0.3;
		if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
					- (game->ray.dirx * 0.3 * 2))] == '0')
			game->ray.py -= game->ray.dirx * 0.3;
	}
}
