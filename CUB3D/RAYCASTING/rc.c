#include "../LIB/cub3d.h"

/* ---------------
update the ray length to when it collides with an object (wall)
1. check length to which axis is smaller
2. update all lengths (start position, length to the next grid line)

void	distance_pw(t_map *game, int wall)
{
	while (wall == 0)
	{
		if (game->ray->lenx < game->ray->leny)
		{
			game->ray->lenx += game->ray->delta_x;
			game->ray->col += game->ray->s2d_col;
			if (game->ray->pdx < 0)
				game->ray->hit_dir = NORTH;
			else
				game->ray->hit_dir = SOUTH;
		}
		else
		{
			game->ray->leny += game->ray->delta_y;
			game->ray->row += game->ray->s2d_row;
			if (game->ray->pdy < 0)
				game->ray->hit_dir = EAST;
			else
				game->ray->hit_dir = WEST;
		}
		if (game->map->map[game->ray->row][game->ray->col] == 1)
			wall = 1;
	}
}

calculate height and position of the wall to draw
depending on hit_dir, distance to the wall = use ray length + delta
after distance calculated => height = proportion of total height
finally, vertical position of the wall

void	wall_creation(t_map *game)
{
	if (game->ray->hit_dir == NORTH || game->ray->hit_dir == SOUTH)
		game->ray->ray_len = (game->ray->lenx - game->ray->delta_x);
	else
		game->ray->ray_len = (game->ray->leny - game->ray->delta_y);
	game->wall_height = 599 / game->ray->ray_len;
	game->wall_start = -game->wall_height / 2 + (599/2);
	if (game->wall_start < 0)
		game->wall_start = 0;
	game->wall_end = game->wall_height / 2 + (599/2);
	if (game->wall_end >= 599)
		game->wall_end = 599 - 1;
}

retrieve texture to draw the wall depending on the direction


void	wall_texture(t_map *game, int x)
{
	if (game->ray->hit_dir == NORTH)
	{
		texture_retrieve(game, game->text_n);
		line_draw(game, game->text_n, get_texture(game->tex->text_n), x);
	}
	if (game->ray->hit_dir == SOUTH)
	{
		texture_retrieve(game, game->text_s);
		line_draw(game, game->text_s, get_texture(game->tex->text_s), x);
	}
	if (game->ray->hit_dir == EAST)
	{
		texture_retrieve(game, game->text_e);
		line_draw(game, game->text_e, get_texture(game->tex->text_e), x);
	}
	if (game->ray->hit_dir == WEST)
	{
		texture_retrieve(game, game->text_w);
		line_draw(game, game->text_w, get_texture(game->tex->text_w), x);
	}
}
------------------*/

void	ft_swap(t_map *game)
{
	void *tmp;

	tmp = game->img;
	game->img = game->imgbis;
	game->imgbis = tmp;
	tmp = game->addr;
	game->addr = game->addrbis;
	game->addrbis = tmp;
}

/*-----------------
ray->x = coordinate x of the pixel being rendered
800 = WIDTH of the window
x = current column we're on
------------------*/

int		raycaster(t_map *game, t_rayc *ray)
{
	ray->x = 0;
	while (ray->x < game->width)
	{
		init_ray(game);
		ray_length(game->ray, game);
		col_color(game, game->ray);
		ray->x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	forward(game);
	backward(game);
	left(game);
	right(game);
	ft_swap(game);
	return (0);
}