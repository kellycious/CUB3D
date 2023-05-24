#include "../LIB/cub3d.h"

void	r_left(t_map *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->ray.dirx;
	old_planex = game->ray.planx;
	game->ray.dirx = game->ray.dirx * cos(0.15)
		- game->ray.diry * sin(0.15);
	game->ray.diry = old_dirx * sin(0.15)
		+ game->ray.diry * cos(0.15);
	game->ray.planx = game->ray.planx * cos(0.15)
		- game->ray.plany * sin(0.15);
	game->ray.plany = old_planex * sin(0.15)
		+ game->ray.plany * cos(0.15);
}

void	r_right(t_map *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->ray.dirx;
	old_planex = game->ray.planx;
	game->ray.dirx = game->ray.dirx * cos(-0.15)
		- game->ray.diry * sin(-0.15);
	game->ray.diry = old_dirx * sin(-0.15)
		+ game->ray.diry * cos(- 0.15);
	game->ray.planx = game->ray.planx * cos(-0.15)
		- game->ray.plany * sin(-0.15);
	game->ray.plany = old_planex * sin(-0.15)
		+ game->ray.plany * cos(-0.15);
}

void	move_player(t_map *game)
{
	if (game->player->forward == 1)
		forward(game);
	if (game->player->backward == 1)
		backward(game);
	if (game->player->left == 1)
		left(game);
	if (game->player->right == 1)
		right(game);
	if (game->player->rleft == 1)
		r_left(game);
	if (game->player->rright == 1)
		r_right(game);
}