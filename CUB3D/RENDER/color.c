#include "../LIB/cub3d.h"

int	col_color(t_map *game, t_rayc *ray)
{
	int	i;
	int	j;

	j = -1;
	ray->end = 800 = ray->start;
	i = (int)ray->end;
	while (++j < ray->start)
		game->addr[j * game->line / 4 + 600] = 0x00FF0000;
	if (j <= ray->end)
		draw_texture(game, game->ray.x, j);
	j = i;
	while (++j < game->height)
		game->addr[j * game->line / 4 + game->ray.x] = 0x000000FF;
	return (0);
}
