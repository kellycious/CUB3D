#include "../LIB/cub3d.h"

void	forward(t_map *game)
{
	if (game->map[(int)((game->ray.px + (game->ray.dirx
				* 2)))][(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.dirx * 0.15;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				+ (game->ray.diry * 2))] == '0')
		game->ray.py += game->ray.diry * 0.15;
}

void	backward(t_map *game)
{
	if (game->map[(int)((game->ray.px) - (game->ray.dirx
				* 0.15 * 2))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.dirx * 0.15;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				- (game->ray.diry * 0.15 * 2))] == '0')
		game->ray.py -= game->ray.diry * 0.15;
}

void	left(t_map *game)
{
	if (game->map[(int)((game->ray.px) + (game->ray.dirx
				* 0.15 * 2))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.diry * 0.15;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
			+ (game->ray.dirx * 0.15 * 2))] == '0')
		game->ray.py += game->ray.dirx * 0.15;
}

void	right(t_map *game)
{
	if (game->map[(int)((game->ray.px) - (game->ray.diry
				* 0.15 * 2))][(int)(game->ray.py)] == '0')
		game->ray.py += game->ray.dirx* 0.15;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				- (game->ray.dirx * 0.15 * 2))] == '0')
		game->ray.py -= game->ray.dirx * 0.15;
}
