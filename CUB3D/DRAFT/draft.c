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

/*-------------------
draw vertical line of pixel
step to map the structure onto the wall
starting position of the texture
position from top to bottom of each pixel
put pixel on the screen

void	line_draw(t_map *game, xmp_t *texture, int **buffer, int x)
{
	int		y;
	double	position;
	double	step;
	int 	screeny;

	step = 1.0 * texture->texture.height / game->wall_height;
	position = ((double)game->wall_start - (double)599 / 2.0 
		+ (double)game->wall_height / 2.0) * step;
	if (position < 0)
		position = 0;
	screeny = game->wall_start;
	while (screeny < game->wall_end)
	{
		y = (int)position;
		if (position > texture->texture.height - 1)
			position = texture->texture.height - 1;
		position = position + step;
		mlx_put_pixel(game->render, x, screeny, buffer[y][game->tex]);
		screeny++;
	}
}

--------------------*/
