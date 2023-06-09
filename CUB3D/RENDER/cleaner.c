/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:46:48 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/26 17:47:56 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_cleaner(t_map *game, char *error)
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
	free(game->player);
	ft_clean(game, game->elements);
	ft_putstr_fd(error, 2);
	exit(0);
}

int	exit_game(t_map *game)
{
	return (ft_cleaner(game, NULL), 0);
}
