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
	game->player->col = game->player_y + 0.5;
	game->player->row = game->player_x + 0.5;
}

static void	player_init2(t_map *game, char direction)
{
	if (direction == 'E')
	{
		game->pdx = 1;
		game->pdy = 0;
		game->ray->disp_x = 0;
		game->ray->disp_y = 0.66;
	}
	if (direction == 'W')
	{
		game->pdx = -1;
		game->pdy = 0;
		game->ray->disp_x = -0.66;
		game->ray->disp_y = 0;
	}
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
		game->pdx = 0;
		game->pdy = -1;
		game->ray->disp_x = 0.66;
		game->ray->disp_y = 0;
	}
	if (direction == 'S')
	{
		game->pdx = 0;
		game->pdy = 1;
		game->ray->disp_x = -0.66;
		game->ray->disp_y = 0;
	}
	player_init2(game, direction);
}
