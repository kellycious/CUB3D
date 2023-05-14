#include "../LIB/cub3d.h"

/* ---------------
fill step and length var: longueur segment du rayon selon sa direction
1. check if the vector is pos or neg => to set if we're tracing 
   backwards or forward (step)
2. distance to next vertical grid line : start.x * current g.line
------------------ */

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
	ray_hit_length(ray);
}

/* ---------------
1.Depending on the player move (up/down/right/left) 
   we use pi or pi/2 as the angle
2.Start registers the position of the player at the start
3. dir = length of the adjacent side of the ray's dir vector
	ps: length of hypothenuse always 1 
4.gline = angle between ray and axis
------------------ */

void	ft_init_ray(t_rayc *ray, t_map *map)
{
	ray->angle = angle;
	ray->start.x = map->player_x;
	ray->start.y = map->player_y;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->gline.x = 0;
	ray->gline.y = 0;
	ray->istartx = (int)ray->start.x;
	ray->istarty = (int)ray->start.y;
	dir_init(map, ray);
	ray_length(ray);
}

/* ---------------
update the ray length to when it collides with an object (wall)
1. check length to which axis is smaller
2. update all lengths (start position, length to the next grid line)
------------------ */

void	ray_hit_length(t_rayc *ray)
{
	float	distance;
	if (ray->length.x < ray->length.y)
	{
		ray->istartx += ray->step.x;
		distance = ray->length.x;
		ray->length.x += ray->unit.x;
		if (ray->step.x == -1)
			ray->hit_dir = WEST;
		else
			ray->hit_dir = EAST;
	}
	else
	{
		ray->istarty += ray->step.y;
		distance = ray->length.y;
		ray->length.y += ray->gline.y;
		if (ray->step.y == -1)
			ray->hit_dir = NORTH;
		else
			ray->hit_dir = SOUTH;
	}
	if (game->map[ray->length.x][ray->length.y] == '1')
		ray->hit = 1;
	draw_ray(ray, distance);
}

void	draw_ray(t_rayc *ray, float distance)
{
	if (ray->hit == 1)
	{
		ray->result.x = ray->start.x + ray->dir.x * distance;
		ray->result.y = ray->start.y + ray->dir.y * distance;
		ray->distance = distance;
	}
}
/* ---------------
check if it does hit a wall or not
if distance < max, then check if the cell is a wall (1)
if it does, update the exact hit point of the ray on the wall
distance: 0.0f so at least one loop is executed


int	ray_caster(t_map *map, t_rayc *ray, float max)
{
	int		hit;
	float	distance;

	distance = 0.0f;
	hit = 0;
	while (!hit && distance < max)
	{
		distance = ray_hit_length(ray);
		hit = (map->cub[ray->istartx][ray->istarty] == '1');
	}
	if (hit)
	{
		ray->result.x = ray->start.x + ray->dir.x * distance;
		ray->result.y = ray->start.y + ray->dir.y * distance;
		ray->distance = distance;
	}
	return (hit);
}

updating the player position and checking if it hits a wall
0.1, distance between player and wall needs to be greater


void	move_player(t_map *map, float angle)
{
	float const	x = 0.1f * cos(map->player_angle + angle);
	float const	y = 0.1f * sin(map->player_angle + angle);
	int			i;
	char		*cardinal;
	t_rayc		*ray;

	cardinal = "NSWE";
	i = 0;
	while (cardinal[i] != p_position(map))
		i++;
	map->player_angle = i * M_PI_2;
	ft_init_ray(&ray, &map, map->player_angle + angle);
	if (!ray_caster(map, &ray, 0.1) || ray->distance > 0.1)
	{
		map->player_x += x;
		map->player_y += y;
	}
}
------------------ */

