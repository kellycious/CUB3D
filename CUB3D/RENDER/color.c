#include "../LIB/cub3d.h"

static int	rgbtohex(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	col_color(t_map *game, t_rayc *ray)
{
	int	i;
	int	j;

	j = -1;
	ray->end = 600 - ray->starty;
	i = (int)ray->end;
	while (++j < ray->starty)
		game->addr[j * game->line / 4 + game->ray->x] = rgbtohex(game->ceiling_r, game->ceiling_g, game->ceiling_b, 0xff);
	if (j <= ray->end)
		draw_texture(game, game->ray->x, j);
	j = i;
	while (++j < 600)
		game->addr[j * game->line / 4 + game->ray->x] = rgbtohex(game->floor_r, game->floor_g, game->floor_b, 0xff);
	return (0);
}
