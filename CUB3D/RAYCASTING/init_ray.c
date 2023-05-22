#include "../LIB/cub3d.h"

void	init_ray(t_map *game)
{
	player_init(game, p_position(game));
	game->ray->hit = 0;
	game->ray->cam = 2 * game->ray->x / (double)800 - 1;
	game->ray->dirx = game->pdx + game->ray->disp_x * game->ray->cam;
	game->ray->diry = game->pdy + game->ray->disp_y * game->ray->cam;
	game->ray->istartx = (int)game->player->col;
	game->ray->istarty = (int)game->player->row;
	if (game->ray->diry == 0)
		game->ray->gline.x = 0;
	else if (game->ray->dirx == 0)
		game->ray->gline.x = 1;
	else
		game->ray->gline.x = sqrt(1 + (game->ray->diry * game->ray->diry)
				/ (game->ray->dirx * game->ray->dirx));
	if (game->ray->dirx == 0)
		game->ray->gline.y = 0;
	else if (game->ray->diry == 0)
		game->ray->gline.y = 1;
	else
		game->ray->gline.y = sqrt(1 + (game->ray->dirx * game->ray->dirx)
				/ (game->ray->diry * game->ray->diry));
}

/* ---------------
fill step and length var: longueur segment du rayon selon sa direction
1. check if the vector is pos or neg => to set if we're tracing 
   backwards or forward (step)
2. distance to next vertical grid line : start.x * current g.line
------------------ */

void	ray_length(t_rayc *ray, t_map *game)
{
	if (ray->dirx < 0)
	{
		ray->step.x = -1;
		ray->length.x = (game->player->row - ray->istartx) * ray->gline.x;
	}
	else
	{
		ray->step.x = 1;
		ray->length.x = ((ray->istartx + 1) - game->player->row) * ray->gline.x;
	}
	if (ray->diry < 0)
	{
		ray->step.y = -1;
		ray->length.y = (game->player->col - ray->istarty) * ray->gline.y;
	}
	else
	{
		ray->step.y = 1;
		ray->length.y = ((ray->istarty + 1) - game->player->col) * ray->gline.y;
	}
	ray_hit_length(ray, game);
}

/* ---------------
update the ray length to when it collides with an object (wall)
1. check length to which axis is smaller
2. update all lengths (start position, length to the next grid line)
------------------ */

void	ray_hit_length(t_rayc *ray, t_map *game)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{		
		if (ray->length.x < ray->length.y)
		{
			ray->length.x += ray->gline.x;
			ray->istartx += ray->step.x;
			ray->hit_dir = 0;
		}
		else
		{
			ray->length.y += ray->gline.y;
			ray->istarty += ray->step.y;
			ray->hit_dir = 1;
		}
		if (game->map[game->ray->istartx][game->ray->istarty] == '1')
			ray->hit = 1;
	}
	draw_ray(game);
}

void	draw_ray(t_map *game)
{
	if (game->ray->hit_dir == NORTH)
		game->ray->pwall = (double)game->ray->istartx - game->player->col
			+ (1 - game->ray->step.x) / 2 / game->ray->dirx;
	else
		game->ray->pwall = (double)game->ray->istarty - game->player->row
			+ (1 - game->ray->step.y) / 2 / game->ray->diry;
	game->ray->line_height = (int)800 / game->ray->pwall;
	game->ray->starty = -game->ray->line_height / 2 + 600 / 2;
	if (game->ray->starty < 0)
		game->ray->starty = 0;
	game->ray->end = game->ray->line_height / 2 + 600 / 2;
	if (game->ray->end >= 600 || game->ray->end < 0)
		game->ray->end = 599;
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