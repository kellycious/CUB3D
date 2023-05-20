#include "../LIB/cub3d.h"

void	exit_game(t_map *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->imgbis)
		mlx_destroy_image(game->mlx, game->imgbis);
	if (game->txt[0].img)
		mlx_destroy_image(game->mlx, game->txt[0].img);
	if (game->txt[1].img)
		mlx_destroy_image(game->mlx, game->txt[1].img);
	if (game->txt[2].img)
		mlx_destroy_image(game->mlx, game->txt[2].img);
	if (game->txt[3].img)
		mlx_destroy_image(game->mlx, game->txt[3].img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_cleaner(game, NULL);
}