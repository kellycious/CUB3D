
#include "../LIB/cub3d.h"

/*

fill step and length var: longueur segment du rayon selon sa direction
1. check if the vector is pos or neg => to set if we're tracing backwards or forward (step)
2. distance to next vertical grid line : start.x * current g.line

*/

void	ray_length(t_rayc *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->length.x = (ray->start.x - ray->istartx) * ray->gline.x;
	}
	else
	{
		ray->step.x = 1;
		ray->length.x = ((ray->istartx + 1) - ray->start.x) * ray->gline.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->length.y = (ray->start.y - ray->istarty) * ray->gline.y;
	}
	else
	{
		ray->step.y = 1;
		ray->length.y = ((ray->istarty + 1) - ray->start.x) * ray->gline.y;
	}
}

/*

1.Depending on the player move (up/down/right/left) we use pi or pi/2 as the angle
2.Start registers the position of the player at the start
3. dir = length of the adjacent side of the ray's dir vector
	ps: length of hypothenuse always 1 
4.gline = angle between ray and axis

*/

void	ft_init_ray(t_rayc *ray, t_map *map, float angle)
{
	ray->angle = angle;
	ray->start.x = map->player_x;
	ray->start.y = map->player_y;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->gline.x = sqrt(1 + pow(ray->dir.y / ray->dir.x, 2));
	ray->gline.y = sqrt(1 + pow(ray->dir.x / ray->dir.y, 2));
	ray->istartx = (int)ray->start.x;
	ray->istarty = (int)ray->start.y;
}

/*

update the ray length to when it collides with an object (wall)


*/

float	ray_hit_length(t_rayc *ray)
{
	float	distance;

	if (ray->length.x < ray->length.y)
	{
		ray->istartx += ray->step.x;
		distance = ray->length.x;
		ray->length.x += ray->unit.x;
	}
}