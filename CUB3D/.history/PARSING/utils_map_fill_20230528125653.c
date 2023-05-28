/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:44:53 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 12:56:53 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_player_position(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N')
		map->n = true;
	else if (map->map[i][j] == 'S')
		map->s = true;
	else if (map->map[i][j] == 'W')
		map->w = true;
	else if (map->map[i][j] == 'E')
		map->e = true;
}

void	ft_change_to(t_map *map, int i, int j)
{
	if (map->n == true)
		map->map_fill[i][j] = 'N';
	else if (map->s == true)
		map->map_fill[i][j] = 'S';
	else if (map->w == true)
		map->map_fill[i][j] = 'W';
	else if (map->e == true)
		map->map_fill[i][j] = 'E';
}

int	ft_is_player(t_map *map, int i, int j)
{
	if (map->map_fill[i][j] == 'N' || map->map_fill[i][j] == 'S'
		|| map->map_fill[i][j] == 'E' || map->map_fill[i][j] == 'W')
		return (1);
	return (0);
}

int	ft_check_player_around(t_map *map, int i, int j)
{
	if ((map->map_fill[i][j] == 'N' || map->map_fill[i][j] == 'S'
		|| map->map_fill[i][j] == 'E' || map->map_fill[i][j] == 'W')
		&& ((map->map_fill[i][j + 1] != '1' && !ft_is_player(map, i, j + 1))
		|| (map->map_fill[i][j - 1] != '1' && !ft_is_player(map, i, j - 1))
		|| (map->map_fill[i + 1][j] != '1' && !ft_is_player(map, i + 1, j))
		|| (map->map_fill[i - 1][j] != '1' && !ft_is_player(map, i - 1, j))))
		return (1);
	return (0);
}

int	ft_check_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_fill[i])
	{
		j = -1;
		while (map->map_fill[i][++j])
			if (ft_check_player_around(map, i, j) == 1)
				return (ft_not_closed_and_clean(map), 0);
		i++;
	}
	return (0);
}
