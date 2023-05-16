#include "../LIB/cub3d.h"

int	col_color(t_map *game, t_rayc *ray)
{
	int	i;
	int	j;

	j = -1;
	ray->result.x = 800 = ray->result.y;
	i = (int)ray->result.x;
	while (++j < ray->result.y)
		game->addr[j * game->line / 4 + 600] = 0x00FF0000;
	if (j <= )
}