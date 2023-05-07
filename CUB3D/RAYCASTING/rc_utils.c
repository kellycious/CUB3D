
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