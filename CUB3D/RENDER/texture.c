#include "../LIB/cub3d.h"

void	texture_init(t_map *game)
{
	game->texture->text_n = mlx_load_xpm42(game->no);
	if (!game->texture->text_n)
		return (ft_cleaner(game, "texture NORTH failed\n"));
	game->texture->text_s = mlx_load_xpm42(game->so);
	if (!game->texture->text_s)
		return (ft_cleaner(game, "texture SOUTH failed\n"));
	game->texture->text_w = mlx_load_xpm42(game->we);
	if (!game->texture->text_w)
		return (ft_cleaner(game, "texture WEST failed\n"));
	game->texture->text_e = mlx_load_xpm42(game->ea);
	if (!game->texture->text_e)
		return (ft_cleaner(game, "texture EAST failed\n"));
	game->texture->n = get_texture(game->texture->text_n);
	game->texture->s = get_texture(game->texture->text_s);
	game->texture->w = get_texture(game->texture->text_w);
	game->texture->e = get_texture(game->texture->text_e);
}

void	texture_retrieve(t_map *game, xpm_t *texture)
{
	double	wall;

	if (game->ray->hit_dir == NORTH || game->ray->hit_dir == SOUTH)
		wall = game->player->row + game->ray->ray_len * game->ray->pdy;
	else
		wall = game->player->col + game->ray->ray_len * game->ray->pdx;
	wall = wall - (int)wall;
	game->tex = (int)(wall * (double)texture->texture.width);
	if ((game->ray->hit_dir == NORTH || game->ray->hit_dir == SOUTH)
		&& game->ray->pdx > 0)
		game->tex = texture->texture.width- game->tex - 1;
	if ((game->ray->hit_dir == EAST || game->ray->hit_dir == WEST)
		&& game->ray->pdy < 0)
		game->tex = texture->texture.width - game->tex - 1;
}

/*-------------------
draw vertical line of pixel
step to map the structure onto the wall
starting position of the texture
position from top to bottom of each pixel
put pixel on the screen
--------------------*/

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

int	rgb_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
/*-------------------
adding +4 to the width and height to avoid segfault
return value of each pixel
RGBA values stored
--------------------*/

int	**get_texture(xpm_t *texture)
{
	int	**buffer;
	int	i;
	int	j;

	buffer = ft_calloc(sizeof(int *), texture->texture.height + 1);
	i = 3;
	while (++i < (int)texture->texture.height + 4)
	{
		j = 3;
		buffer[i - 4] = ft_calloc(sizeof(int), texture->texture.width);
		while (++j < (int)texture->texture.width + 4)
			buffer[i - 4][j - 4]
				= rgb_int(texture->texture.pixels[(texture->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 0],
					texture->texture.pixels[(texture->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 1],
					texture->texture.pixels[(texture->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 2]);
	}
	return (buffer);
}