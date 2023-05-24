/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:46:55 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/25 00:49:12 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static int	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (0);
}

int	render_map(t_map *game)
{
	player_init(game, p_position(game));
	init_mlx(game);
	game->win = mlx_new_window(game->mlx, game->widthy,
			game->heighty, "PEPE CLOWN");
	texture_img(game);
	game->img = mlx_new_image(game->mlx, game->widthy, game->heighty);
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp, &game->line,
			&game->endian);
	game->imgbis = mlx_new_image(game->mlx, game->widthy, game->heighty);
	game->addrbis = (int *)mlx_get_data_addr(game->imgbis, &game->bpp,
			&game->line, &game->endian);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 33, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, raycaster, game);
	mlx_loop(game->mlx);
	return (0);
}
