#include "../LIB/cub3d.h"

/* -------------------------------------------------
recalculating the ray direction and camera plane
angle are calculated from cos and sin of the angle
via the rotation matrix
--------------------------------------------------*/

void	r_left(t_map *game)
{
	double	odirx;
	double	oplanx;

	odirx = game->ray.dirx;
	oplanx = game->ray.planx;
	game->ray.dirx = game->ray.dirx * cos(0.05)
		- game->ray.diry * sin(0.05);
	game->ray.diry = odirx * sin(0.05)
		+ game->ray.diry * cos(0.05);
	game->ray.planx = game->ray.planx * cos(0.05)
		- game->ray.plany * sin(0.05);
	game->ray.plany = oplanx * sin(0.05)
		+ game->ray.plany * cos(0.05);
}

void	r_right(t_map *game)
{
	double	odirx;
	double	oplanx;

	odirx = game->ray.dirx;
	oplanx = game->ray.planx;
	game->ray.dirx = game->ray.dirx * cos(-0.05)
		- game->ray.diry * sin(-0.05);
	game->ray.diry = odirx * sin(-0.05)
		+ game->ray.diry * cos(-0.05);
	game->ray.planx = game->ray.planx * cos(-0.05)
		- game->ray.plany * sin(-0.05);
	game->ray.plany = oplanx * sin(-0.05)
		+ game->ray.plany * cos(-0.05);
}

int	move_player(t_map *game)
{
	if (game->player->forward == 1)
		return (forward(game), 1);
	if (game->player->backward == 1)
		return (backward(game), 1);
	if (game->player->left == 1)
		return (right(game), 1);
	if (game->player->right == 1)
		return (left(game), 1);
	if (game->player->rleft == 1)
		return (r_left(game), 1);
	if (game->player->rright == 1)
		return (r_right(game), 1);
	return (0);
}