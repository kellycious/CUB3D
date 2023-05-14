#include "../LIB/cub3d.h"

void	ft_cleaner(t_map *game, char *error)
{
	int	i;

	i = 0;
	ft_clean(game);
	if (game->txt[0].img)
			mlx_destroy_image(game->mlx, game->txt[0].img);
	if (game->txt[1].img)
			mlx_destroy_image(game->mlx, game->txt[1].img);
	if (game->txt[2].img)
			mlx_destroy_image(game->mlx, game->txt[2].img);
	if (game->txt[3].img)
			mlx_destroy_image(game->mlx, game->txt[3].img);
	if (game->txt[4].img)
			mlx_destroy_image(game->mlx, game->txt[4].img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd(error, 2);
	exit(0);
}