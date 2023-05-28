/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:12:39 by fwong             #+#    #+#             */
/*   Updated: 2023/05/27 02:22:02 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	filler_map(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (j <= (int)game->width && (game->map[i][j] == '\0'
				|| !game->map[i][j]))
				game->map[i][j] = '2';
			printf("map[%d][%d] = %c", i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
}