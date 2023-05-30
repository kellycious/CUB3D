/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:46:55 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/30 19:59:40 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static int	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_cleaner(map, "Error\nmlx init\n"), 1);
	return (0);
}

static void	render(t_map *game)
{
	game->img = mlx_new_image(game->mlx, game->widthy, game->heighty);
	if (!game->img)
		return (ft_cleaner(game, "Error\nmlx new image\n"));
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp, &game->line,
			&game->endian);
	if (!game->addr)
		return (ft_cleaner(game, "Error\nmlx get data addr\n"));
	game->imgbis = mlx_new_image(game->mlx, game->widthy, game->heighty);
	if (!game->imgbis)
		return (ft_cleaner(game, "Error\nmlx new image\n"));
	game->addrbis = (int *)mlx_get_data_addr(game->imgbis, &game->bpp,
			&game->line, &game->endian);
	if (!game->addrbis)
		return (ft_cleaner(game, "Error\nmlx get data addr\n"));
}

int	render_map(t_map *game)
{
	player_init(game, p_position(game));
	init_mlx(game);
	game->win = mlx_new_window(game->mlx, game->widthy,
			game->heighty, "PEPE CLOWN");
	texture_img(game);
	render(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 33, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, raycaster, game);
	mlx_loop(game->mlx);
	return (0);
}
