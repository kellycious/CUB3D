#include "../LIB/cub3d.h"

static void	init_ray(t_map *game)
{
	player_init(game, p_position(game));
	game->ray.hit = 0;
	game->ray.pwalld = 0;
	game->ray.cam = 2 * game->ray.x / (double)game->widthy - 1;
	game->ray.rdx = game->ray.dirx + game->ray.planx * game->ray.cam;
	game->ray.rdy = game->ray.diry + game->ray.plany * game->ray.cam;
	game->ray.mx = (int)game->ray.px;
	game->ray.my = (int)game->ray.py;
	if (game->ray.rdy == 0)
		game->ray.ddx = 0;
	else if (game->ray.rdx == 0)
		game->ray.ddx = 1;
	else
		game->ray.ddx = sqrt(1 + (game->ray.rdy
					* game->ray.rdy) / (game->ray.rdx
					* game->ray.rdx));
	if (game->ray.rdx == 0)
		game->ray.ddy = 0;
	else if (game->ray.rdy == 0)
		game->ray.ddy = 1;
	else
		game->ray.ddy = sqrt(1 + (game->ray.rdx
					* game->ray.rdx) / (game->ray.rdy
					* game->ray.rdy));
	return(init_ray2(game));
}

void	init_ray2(t_map *game)
{
	if (game->ray.rdx < 0)
	{
		game->ray.stepx = -1;
		game->ray.sdx = (game->ray.px - game->ray.mx) * game->ray.ddx;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.sdx
			= (game->ray.mx + 1.0 - game->ray.px) * game->ray.ddx;
	}
	if (game->ray.rdy < 0)
	{
		game->ray.stepy = -1;
		game->ray.sdy = (game->ray.py - game->ray.my) * game->ray.ddy;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.sdy
			= (game->ray.my + 1.0 - game->ray.py) * game->ray.ddy;
	}
}

void	wallcheck(t_map *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		if (game->ray.sdx < game->ray.sdy)
		{
			game->ray.sdx += game->ray.ddx;
			game->ray.mx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sdy += game->ray.ddy;
			game->ray.my += game->ray.stepy;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mx][game->ray.my] == '1')
			game->ray.hit = 1;
	}
	return (wallhit(game));
}

void	wallhit(t_map *game)
{
	if (game->ray.side == 0)
		game->ray.pwalld = ((double)game->ray.mx - game->ray.px
				+ (1 - (double)game->ray.stepx) / 2) / game->ray.rdx;
	else
		game->ray.pwalld = ((double)game->ray.my - game->ray.py
				+ (1 - (double)game->ray.stepy) / 2) / game->ray.rdy;
	game->ray.lineheight = (int)(game->heighty / game->ray.pwalld);
	game->ray.drawstart = -game->ray.lineheight / 2 + game->heighty / 2;
	if (game->ray.drawstart < 0)
		game->ray.drawstart = 0;
	game->ray.drawend = game->ray.lineheight / 2 + game->widthy / 2;
	if (game->ray.drawend >= game->heighty || game->ray.drawend < 0)
		game->ray.drawend = game->heighty - 1;
	return (draw_texture(game));
}

void	init_texture(t_map *game)
{
	if (game->ray.side == 0 && game->ray.rdx < 0)
		game->tex.dir = NORTH;
	if (game->ray.side == 0 && game->ray.rdx >= 0)
		game->tex.dir = SOUTH;
	if (game->ray.side == 1 && game->ray.rdy < 0)
		game->tex.dir = EAST;
	if (game->ray.side == 1 && game->ray.rdy >= 0)
		game->tex.dir = WEST;
	if (game->ray.side == 0)
		game->tex.wallx = game->ray.py + game->ray.pwalld \
						* game->ray.rdy;
	else
		game->tex.wallx = game->ray.px + game->ray.pwalld \
						* game->ray.rdx;
	game->tex.wallx -= floor(game->tex.wallx);
}

void	gtext_wall(t_map *game, int x, int y)
{
	y = game->ray.drawstart - 1;
	init_texture(game);
	game->tex.step = 1.0 * game->txt[0].height / game->ray.lineheight;
	game->tex.texx = (int)(game->tex.wallx * (double)game->txt
		[game->tex.dir].width);
	if ((game->ray.side == 0 && game->ray.rdx > 0)
		|| (game->ray.side == 1 && game->ray.rdy < 0))
		game->tex.texx = game->txt[game->tex.dir].width
			- game->tex.texx - 1;
	game->tex.pos = (game->ray.drawstart - game->heighty / 2
			+ game->ray.lineheight / 2) * game->tex.step;
	while (++y <= game->ray.drawend)
	{
		game->tex.texy = (int)game->tex.pos
			& (game->txt[game->tex.dir].height - 1);
		game->tex.pos += game->tex.step;
		if (x < game->widthy && y < game->heighty)
			game->addr[y * game->line / 4 + x]
				= game->txt[game->tex.dir].addr[game->tex.texy
				* game->txt[game->tex.dir].line
				/ 4 + game->tex.texx];
	}
}

int	raycaster(t_map *game)
{
	game->ray.x = 0;
	while (game->ray.x < game->widthy)
	{
		init_ray(game);
		wallcheck(game);
		game->ray.x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	forward(game);
	backward(game);
	left(game);
	right(game);
	swapy(game);
	return (0);
}
