#include "../LIB/cub3d.h"

/*---------
Find at which direction the player is facing
-----------*/

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
	return (0);
}

/*---------
init column and row of the player
adding 0.5 so it is in the middle of the square
-----------*/

static void	pcr_init(t_map *game)
{
	game->ray.py = game->player_y + 0.5;
	game->ray.px = game->player_x + 0.5;
}

/*---------
Find at which direction the player is facing
using 0.66 as a constant for good balance between 
distorsion and visual accuracy
-----------*/

void	player_init(t_map *game, char direction)
{
	pcr_init(game);
	if (direction == 'N')
		game->ray.dirx = -1;
	if (direction == 'S')
		game->ray.dirx = 1;
	if (direction == 'E')
		game->ray.diry = 1;
	if (direction == 'W')
		game->ray.diry = -1;
	if (direction == 'N')
		game->ray.plany = 0.66;
	if (direction == 'S')
		game->ray.plany = -0.66;
	if (direction == 'E')
		game->ray.planx = 0.66;
	if (direction == 'W')
		game->ray.planx = -0.66;
}
