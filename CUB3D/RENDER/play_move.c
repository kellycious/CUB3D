#include "../LIB/cub3d.h"

void	forward(t_map *game)
{
	if (game->map[(int)(game->ray.px + game->ray.dirx)]
			[(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.dirx * 0.14;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				+ (game->ray.diry))] == '0')
		game->ray.py += game->ray.diry * 0.14;
}

void	backward(t_map *game)
{
	if (game->map[(int)(game->ray.px - (game->ray.dirx
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.dirx * 0.14;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				- (game->ray.diry * 1))] == '0')
		game->ray.py -= game->ray.diry * 0.14;
}

void	left(t_map *game)
{
	if (game->map[(int)((game->ray.px) + (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.diry * 0.14;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				+ (game->ray.dirx * 1))] == '0')
		game->ray.py += game->ray.dirx * 0.14;
}

void	right(t_map *game)
{
	if (game->map[(int)((game->ray.px) - (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.diry * 0.14;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				- (game->ray.dirx * 1))] == '0')
		game->ray.py -= game->ray.dirx * 0.14;
}
