#include "../LIB/cub3d.h"

void	texture_pix(t_map *game)
{
	if (!(game->txt[NORTH]->addr = (int *)mlx_get_data_addr(game->txt[NORTH]->img,
				&game->txt[NORTH]->bpp, &game->txt[NORTH]->line,
				&game->txt[NORTH]->endian)))
		return (ft_cleaner(game, "Error: xpm img NORTH\n"));
	if (!(game->txt[SOUTH]->addr = (int *)mlx_get_data_addr(game->txt[SOUTH]->img,
				&game->txt[SOUTH]->bpp, &game->txt[SOUTH]->line,
				&game->txt[SOUTH]->endian)))
		return (ft_cleaner(game, "Error: xpm img SOUTH\n"));
	if (!(game->txt[WEST]->addr = (int *)mlx_get_data_addr(game->txt[WEST]->img,
				&game->txt[WEST]->bpp, &game->txt[WEST]->line,
				&game->txt[WEST]->endian)))
		return (ft_cleaner(game, "Error: xpm img WEST\n"));
	if (!(game->txt[EAST]->addr = (int *)mlx_get_data_addr(game->txt[EAST]->img,
				&game->txt[EAST]->bpp, &game->txt[EAST]->line,
				&game->txt[EAST]->endian)))
		return (ft_cleaner(game, "Error: xpm img EAST\n"));
}

void	texture_img(t_map *game)
{
	game->txt[NORTH]->img = mlx_xpm_file_to_image(game->mlx, game->no,
			(int *)800, (int *)600);
	game->txt[SOUTH]->img = mlx_xpm_file_to_image(game->mlx, game->so,
			(int *)800, (int *)600);
	game->txt[WEST]->img = mlx_xpm_file_to_image(game->mlx, game->we,
			(int *)800, (int *)600);
	game->txt[EAST]->img = mlx_xpm_file_to_image(game->mlx, game->ea,
			(int *)800, (int *)600);
	texture_pix(game);
}

void	draw_texture(t_map *game, int x, int y)
{
	y = game->ray->starty - 1;
	init_texture(game);
	game->tex->step = 1.0 * game->txt[NORTH]->height
		/ game->ray->line_height;
	game->tex->texx = (int)game->tex->wallx
		* (double)(game->txt[game->tex->dir]->width);
	if ((game->ray->hit_dir == NORTH && game->ray->dir.x > 0)
		|| (game->ray->hit_dir == SOUTH && game->ray->dir.y < 0))
		game->tex->texx = game->txt[game->tex->dir]->width
			- game->tex->texx - 1;
		game->tex->pos = (game->ray->starty - game->height / 2
			+ game->ray->line_height / 2) * game->tex->step;
	while (++y < game->ray->end)
	{
		game->tex->texy = (int)game->tex->pos
			& (game->txt[game->tex->dir]->height - 1);
		game->tex->pos += game->tex->step;
		if (y < game->height && x < game->width)
			game->addr[(y * game->line) / 4 + x]
				= game->txt[game->tex->dir]->addr[(game->tex->texy
					* game->txt[game->tex->dir]->line) / 4 + game->tex->texx];
	}
}

/*------------
floor = convert float to int
-------------*/
void	init_texture(t_map *game)
{
	if (game->ray->hit_dir == NORTH && game->ray->dir.x < 0)
		game->tex->dir = NORTH;
	if (game->ray->hit_dir == NORTH && game->ray->dir.x >= 0)
		game->tex->dir = SOUTH;
	if (game->ray->hit_dir == SOUTH && game->ray->dir.y < 0)
		game->tex->dir = WEST;
	if (game->ray->hit_dir == SOUTH && game->ray->dir.y >= 0)
		game->tex->dir = EAST;
	if (game->ray->hit_dir == NORTH)
		game->tex->wallx = game->player->row + game->ray->pwall
			* game->ray->dir.y;
	else
		game->tex->wallx = game->player->col + game->ray->pwall
			* game->ray->dir.x;
	game->tex->wallx -= floor(game->tex->wallx);
}

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
