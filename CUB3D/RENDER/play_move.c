/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:47:02 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/25 23:48:32 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

/* -------------------------------------------------
check if the map[x][y] is a 0 so the player can move
add ray direction to player position * speed
-------------------------------------------------*/

void	forward(t_map *game)
{
	if (game->map[(int)(game->ray.px + game->ray.dirx)]
			[(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.dirx * 0.14;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				+ (game->ray.diry))] == '0')
		game->ray.py += game->ray.diry * 0.14;
}

void	backward(t_map *game)
{
	if (game->map[(int)(game->ray.px - (game->ray.dirx
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.dirx * 0.14;
	if (game->map[(int)(game->ray.px)][(int)(game->ray.py
				- (game->ray.diry * 1))] == '0')
		game->ray.py -= game->ray.diry * 0.14;
}

void	left(t_map *game)
{
	if (game->map[(int)((game->ray.px) + (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px -= game->ray.diry * 0.14;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				+ (game->ray.dirx * 1))] == '0')
		game->ray.py += game->ray.dirx * 0.14;
}

void	right(t_map *game)
{
	if (game->map[(int)((game->ray.px) - (game->ray.diry
				* 1))][(int)(game->ray.py)] == '0')
		game->ray.px += game->ray.diry * 0.14;
	if (game->map[(int)(game->ray.px)][(int)((game->ray.py)
				- (game->ray.dirx * 1))] == '0')
		game->ray.py -= game->ray.dirx * 0.14;
}
