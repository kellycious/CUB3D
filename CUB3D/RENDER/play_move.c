#include "../LIB/cub3d.h"

void	forward(t_map *game)
{
	if (game->mlx.forward == 1)
	{
		if (game->map[(int)(game->player.row) + (game->ray->dir.x
			* 0.3 * 2)][(int)(game->player.col)] == '0')
			game->player.row += game->ray->dir.x * 0.3;
		if (game->map[(int)(game->player.row)][(int)(game->player.col)
			+ (game->ray->dir.y * 0.3 * 2)] == '0')
			game->player.col += game->ray->dir.y * 0.3;
	}
}

void	backward(t_map *game)
{
	if (game->mlx.backward == 1)
	{
		if (game->map[(int)(game->player.row) - (game->ray->dir.x
			* 0.3 * 2)][(int)(game->player.col)] == '0')
			game->player.row -= game->ray->dir.x * 0.3;
		if (game->map[(int)(game->player.row)][(int)(game->player.col)
			- (game->ray->dir.y * 0.3 * 2)] == '0')
			game->player.col -= game->ray->dir.y * 0.3;
	}
}

void	left(t_map *game)
{
	if (game->mlx.left == 1)
	{
		if (game->map[(int)(game->player.row) + (game->ray->dir.y
			* 0.3 * 2)][(int)(game->player.col)] == '0')
			game->player.row -= game->ray->dir.y * 0.3;
		if (game->map[(int)(game->player.row)][(int)(game->player.col)
			+ (game->ray->dir.x * 0.3 * 2)] == '0')
			game->player.col += game->ray->dir.x * 0.3;
	}
}

void	right(t_map *game)
{
	if (game->mlx.right == 1)
	{
		if (game->map[(int)(game->player.row) - (game->ray->dir.y
			* 0.3 * 2)][(int)(game->player.col)] == '0')
			game->player.col += game->ray->dir.y * 0.3;
		if (game->map[(int)(game->player.row)][(int)(game->player.col)
			- (game->ray->dir.x * 0.3 * 2)] == '0')
			game->player.col -= game->ray->dir.x * 0.3;
	}
}