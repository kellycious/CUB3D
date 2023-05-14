#include "../LIB/cub3d.h"

char	p_position(t_map *cub)
{
	if (cub->n == 1)
		return ('N');
	else if (cub->s == 1)
		return ('S');
	else if (cub->w == 1)
		return ('W');
	else if (cub->e == 1)
		return ('E');
}

void	dir_init(t_map *game, t_rayc *ray)
{
	char position;

	position = p_position(ray->map);
	if (position == 'N')
	{
		ray->dir.x = -1;
		ray->gline.y = 0.66;
	}
	if (position == 'S')
	{
		ray->dir.x = 1;
		ray->gline.y = -0.66;
	}
	if (position == 'W')
	{
		ray->dir.y = -1;
		ray->gline.x = -0.66;
	}
	if (position == 'E')
	{
		ray->dir.y = 1;
		ray->gline.x = 0.66;
	}
}