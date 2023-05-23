#include "../LIB/cub3d.h"

void	init_ray(t_map *game)
{
	player_init(game, p_position(game));
	game->ray->hit = 0;
	game->ray->cam = 2 * game->ray->x / (double)game->widthy - 1;
	game->ray->row = game->ray.py;
	game->ray->col = game->ray.px;
	game->ray->rdx = -game->ray.dirx + game->ray->gline.x * game->ray->cam;
	game->ray->rdy = -game->ray->diry + game->ray->gline.y * game->ray->cam;
	game->ray->istartx = (int)game->ray->row;
	game->ray->istarty = (int)game->ray->col;
	game->ray->rdd.x = sqrt(1 + (game->ray->rdy * game->ray->rdy) /
			(game->ray->rdx * game->ray->rdx));
	game->ray->rdd.y = sqrt(1 + (game->ray->rdx * game->ray->rdx) /
			(game->ray->rdy * game->ray->rdy));
	game->ray->hit = 0;
}

/* ---------------
fill step and length var: longueur segment du rayon selon sa direction
1. check if the vector is pos or neg => to set if we're tracing 
   backwards or forward (step)
2. distance to next vertical grid line : start.x * current g.line
------------------ */

void	ray_length(t_rayc *ray, t_map *game)
{
	if (ray->rdx > 0)
	{
		ray->step.x = -1;
		ray->rt.x = (game->ray->row - ray->istartx) * ray->rdd.x;
	}
	else
	{
		ray->step.x = 1;
		ray->rt.x = ((ray->istartx + 1.0) - game->ray->row) * ray->rdd.x;
	}
	if (ray->rdy > 0)
	{
		ray->step.y = -1;
		ray->rt.y = (game->ray->col - ray->istarty) * ray->rdd.y;
	}
	else
	{
		ray->step.y = 1;
		ray->rt.y = ((ray->istarty + 1.0) - game->ray->col) * ray->rdd.y;
	}
}

/* ---------------
update the ray length to when it collides with an object (wall)
1. check length to which axis is smaller
2. update all lengths (start position, length to the next grid line)
------------------ */

int	ray_hit(t_rayc *ray, t_map *game, int texture)
{
	while (ray->hit == 0)
	{		
		if (ray->rt.x < ray->rt.y)
		{
			ray->rt.x += ray->rdd.x;
			ray->istartx += ray->step.x;
			ray->wall = 0;
		}
		else
		{
			ray->rt.y += ray->rdd.y;
			ray->istarty += ray->step.y;
			ray->wall = 1;
		}
		if (game->map[ray->istartx][ray->istarty] == '1')
			ray->hit = 1;
		texture = get_texture(game);
	}
	return (texture);
}
void	ray_size(t_map *game)
{
	if (game->ray->wall == 0)
		game->ray->dist = fabs((game->ray->istartx - game->ray->row 
					+ (1 - game->ray->step.x) / 2) / game->ray->rdx);
	if (game->ray->wall == 1)
		game->ray->dist = fabs((game->ray->istarty - game->ray->col 
					+ (1 - game->ray->step.y) / 2) / game->ray->rdy);
	game->ray->lineh = (int)(game->heighty / game->ray->dist);
	game->ray->lineh = game->heighty / 50;
	game->ray->drawstart = (-1 * (game->ray->lineh)) / 2 + game->heighty / 2;
	game->ray->drawend = (game->ray->lineh) / 2 + game->heighty / 2;
	if (game->ray->drawstart < 0)
		game->ray->drawstart = 0;
	if (game->ray->drawend >= game->heighty)
		game->ray->drawend = game->heighty - 1;
}


