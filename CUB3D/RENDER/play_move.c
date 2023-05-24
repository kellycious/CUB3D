#include "../LIB/cub3d.h"

void	forward(t_map *game)
{
	printf("BF px: %f, py: %f\n", game->ray.px, game->ray.py);
	if (game->map[(int)(game->ray.px + game->ray.dirx)]
			[(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.dirx;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				+ (game->ray.diry))] == '0')
		game->ray.py += game->ray.diry;
	printf("AF px: %f, py: %f\n", game->ray.px, game->ray.py);
}

void	backward(t_map *game)
{
	printf("BB px: %f, py: %f\n", game->ray.px, game->ray.py);
	if (game->map[(int)(game->ray.px - (game->ray.dirx
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.dirx;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				- (game->ray.diry * 1))] == '0')
		game->ray.py -= game->ray.diry;
	printf("AB px: %f, py: %f\n", game->ray.px, game->ray.py);
}

void	left(t_map *game)
{
	printf("BL px: %f, py: %f\n", game->ray.px, game->ray.py);
	if (game->map[(int)((game->ray.px) + (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.diry;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				+ (game->ray.dirx * 1))] == '0')
		game->ray.py += game->ray.dirx;
	printf("AL px: %f, py: %f\n", game->ray.px, game->ray.py);
}

void	right(t_map *game)
{
	printf("BR px: %f, py: %f\n", game->ray.px, game->ray.py);
	if (game->map[(int)((game->ray.px) - (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.diry;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				- (game->ray.dirx * 1))] == '0')
		game->ray.py -= game->ray.dirx;
	printf("AR px: %f, py: %f\n", game->ray.px, game->ray.py);
}
