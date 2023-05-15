#include "../LIB/cub3d.h"

/* ---------------
fill step and length var: longueur segment du rayon selon sa direction
1. check if the vector is pos or neg => to set if we're tracing 
   backwards or forward (step)
2. distance to next vertical grid line : start.x * current g.line
------------------ */

static void	ray_length(t_map *game)
{
	if (game->ray->pdx < 0)
	{
		game->ray->s2d_col = -1;
		game->ray->lenx = (game->player->col - game->ray->col) 
			* ray->delta_x;
	}
	else
	{
		game->ray->s2d_col = 1;
		game->ray->lenx = (game->ray->col + 1.0 - game->player->col) 
			* ray->delta_x;
	}
	if (game->ray->pdy < 0)
	{
		game->ray->s2d_row = -1;
		game->ray->leny = (game->player->row - game->ray->row) 
			* ray->delta_y;
	}
	else
	{
		game->ray->s2d_row = 1;
		game->ray->leny = (game->ray->row + 1.0 - game->player->row) 
			* ray->delta_y;
	}
}
/*------------------------

calculate position + direction of the ray using player position
+ distance bf hit a wall
1e30 = 10 ^ 30 = infinity (to avoid division by 0)
fabs = valeur absolue
-------------------------*/

void	ray_dispos(t_map *game)
{
	game->ray->pdx = game->player->pdx + game->ray->disp_x * game->ray->x;
	game->ray->pdy = game->player->pdy + game->ray->disp_y * game->ray->x;
	game->ray->col = game->player->col;
	if (game->ray->pdx == 0)
		game->ray->delta_x = 1e30;
	else
		game->ray->delta_x = fabs(1 / game->ray->pdx);
	if (game->ray->pdy == 0)
		game->ray->delta_y = 1e30;
	else
		game->ray->delta_y = fabs(1 / game->ray->pdy);
	ray_length(game->ray);
}
