#include "../LIB/cub3d.h"

void	swapy(t_map *game)
{
	void	*tmp;

	tmp = game->img;
	game->img = game->imgbis;
	game->imgbis = tmp;
	tmp = game->addr;
	game->addr = game->addrbis;
	game->addrbis = tmp;
}