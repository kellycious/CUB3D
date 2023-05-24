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
	game->player->forward = 0;
	game->player->backward = 0;
	game->player->left = 0;
	game->player->right = 0;
	game->player->rleft = 0;
	game->player->rright = 0;
	game->ray.py = (double)game->player_y + 0.5;
	game->ray.px = (double)game->player_x + 0.5;
	game->ray.dirx = 0;
	game->ray.diry = 0;
	game->ray.planx = 0;
	game->ray.plany = 0;
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
	{
		game->ray.dirx = -1;
		game->ray.plany = 0.66;
	}
	if (direction == 'S')
	{
		game->ray.dirx = 1;
		game->ray.plany = -0.66;
	}
	if (direction == 'E')
	{
		game->ray.diry = 1;
		game->ray.planx = 0.66;
	}
	if (direction == 'W')
	{
		game->ray.diry = -1;
		game->ray.planx = -0.66;
	}
}
