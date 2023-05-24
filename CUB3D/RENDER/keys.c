/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:46:58 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/25 00:46:59 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	key_press(int keycode, t_map *game)
{
	if (keycode == 'w')
		game->player->forward = 1;
	if (keycode == 's')
		game->player->backward = 1;
	if (keycode == 'a')
		game->player->left = 1;
	if (keycode == 'd')
		game->player->right = 1;
	if (keycode == 65361)
		game->player->rleft = 1;
	if (keycode == 65363)
		game->player->rright = 1;
	if (keycode == 65307)
		exit_game(game);
	return (0);
}

int	key_release(int keycode, t_map *game)
{
	if (keycode == 'w')
		game->player->forward = 0;
	if (keycode == 's')
		game->player->backward = 0;
	if (keycode == 'a')
		game->player->left = 0;
	if (keycode == 'd')
		game->player->right = 0;
	if (keycode == 65361)
		game->player->rleft = 0;
	if (keycode == 65363)
		game->player->rright = 0;
	return (1);
}
