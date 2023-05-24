#include "../LIB/cub3d.h"

/* -------------------------------------------------
hit = check if ray has hit a wall
pwalld = distance from player to wall
cam = x-coordinate on camera plane
rdx = ray direction x
mx = position du joueur + 0.5 pour la centrer
ddx = distance between x and y
sdx = distance between x and x
stepx = step to be taken according to ray direction
---------------------------------------------------*/

static void	init_ray(t_map *game)
{
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
	return (wallcheck(game));
}
/* -------------------------------------------------
Check if next intersection is vertical or 
horizontal grid => check if it is a wall
--------------------------------------------------*/

void	wallcheck(t_map *game)
{
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
	return (wall_coor(game));
}

/* -------------------------------------------------
calculating the details to render part of the wall
pwalld + line height + draw start + draw end 
--------------------------------------------------*/

void	wall_coor(t_map *game)
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

/* -------------------------------------------------
General looping function, covering the whole screen
from bottom to top using the whole raycasting walls
put the img to the window, move the player around
and swap the two buffers to avoid flickering

if we are moving the player, once it is done
replace the player position by a 0 in the map
so it can move again the next time
--------------------------------------------------*/

int	raycaster(t_map *game)
{
	game->ray.x = -1;
	while (++game->ray.x < game->widthy)
		init_ray(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (move_player(game) == 1)
		game->map[game->player_x][game->player_y] = '0';
	swapy(game);
	return (0);
}
