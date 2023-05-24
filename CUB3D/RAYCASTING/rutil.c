/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:46:17 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/25 00:46:25 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	swapy(t_map *game)
{
	void	*tmp;

	tmp = game->img;
	game->img = game->imgbis;
	game->imgbis = tmp;
	tmp = game->addr;
	game->addr = game->addrbis;
	game->addrbis = tmp;
}

/* -------------------------------------------------
taking the texture according to the direction of the
wall to render it on the screen
--------------------------------------------------*/

void	init_texture(t_map *game)
{
	if (game->ray.side == 0 && game->ray.rdx < 0)
		game->tex.dir = NORTH;
	if (game->ray.side == 0 && game->ray.rdx >= 0)
		game->tex.dir = SOUTH;
	if (game->ray.side == 1 && game->ray.rdy < 0)
		game->tex.dir = EAST;
	if (game->ray.side == 1 && game->ray.rdy >= 0)
		game->tex.dir = WEST;
	if (game->ray.side == 0)
		game->tex.wallx = game->ray.py + game->ray.pwalld \
						* game->ray.rdy;
	else
		game->tex.wallx = game->ray.px + game->ray.pwalld \
						* game->ray.rdx;
	game->tex.wallx -= floor(game->tex.wallx);
}
/* -------------------------------------------------
put the right pixel from the texture to render the 
walls accordingly
--------------------------------------------------*/

void	gtext_wall(t_map *game, int x, int y)
{
	y = game->ray.drawstart - 1;
	init_texture(game);
	game->tex.step = 1.0 * game->txt[0].height / game->ray.lineheight;
	game->tex.texx = (int)(game->tex.wallx * (double)game->txt
		[game->tex.dir].width);
	if ((game->ray.side == 0 && game->ray.rdx > 0)
		|| (game->ray.side == 1 && game->ray.rdy < 0))
		game->tex.texx = game->txt[game->tex.dir].width
			- game->tex.texx - 1;
	game->tex.pos = (game->ray.drawstart - game->heighty / 2
			+ game->ray.lineheight / 2) * game->tex.step;
	while (++y <= game->ray.drawend)
	{
		game->tex.texy = (int)game->tex.pos
			& (game->txt[game->tex.dir].height - 1);
		game->tex.pos += game->tex.step;
		if (x < game->widthy && y < game->heighty)
			game->addr[y * game->line / 4 + x]
				= game->txt[game->tex.dir].addr[game->tex.texy
				* game->txt[game->tex.dir].line
				/ 4 + game->tex.texx];
	}
}
