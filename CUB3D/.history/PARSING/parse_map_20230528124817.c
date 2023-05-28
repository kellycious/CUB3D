/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:19:53 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 12:48:17 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	ft_find_map(t_map *map)
{
	int		i;
	int		j;

	i = ft_count_elements(map, 0) + 1;
	while (map->cub[i][0] == '\0')
		i++;
	while (map->cub[i])
	{
		j = 0;
		while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
		{
			if (!(map->cub[i][j] == ' ' || map->cub[i][j] == '\t'
				|| map->cub[i][j] == '1' || map->cub[i][j] == '0'))
				return (ft_elements_error('0', '0', '0', map), 0);
			j++;
		}
		if (map->cub[i][j] == '1' || map->cub[i][j] == '0')
			return (i);
		i++;
	}
	return (0);
}

void	get_map(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	ft_count_line_map(map, elements);
	i = ft_find_map(map);
	j = 0;
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	while (map->cub[i])
	{
		map->map[j] = ft_strdup(map->cub[i]);
		if (map->width < ft_strlen(map->map[j]))
			map->width = ft_strlen(map->map[j]);
		i++;
		j++;
	}
	ft_check_other_char(map);
	ft_find_player(map);
	ft_copy_map(map);
}

int	ft_flood_fill(t_map *map, bool player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_fill[i])
	{
		j = -1;
		while (map->map_fill[i][++j])
		{
			if (ft_check_player(map, i, j) == 1)
			{
				player = true;
				if (ft_change_to_player(map, i, j))
					i = 0;
				else
					return (ft_putstr_fd("Error\nMap not closed\n", 2),
						ft_clean(map, map->elements), exit(0), 0);
			}
		}
		i++;
	}
	if (player == false)
		return (ft_putstr_fd("Error\nNo player\n", 2),
			ft_clean(map, map->elements), exit(0), 0);
	return (1);
}

int	ft_change_to_player(t_map *map, int i, int j)
{
	if (map->map_fill[i][j + 1] == '0')
		ft_change_to(map, i, j + 1);
	else if (ft_closed(map, i, j + 1) == 0)
		return (0);
	if (map->map_fill[i][j - 1] == '0')
		ft_change_to(map, i, j - 1);
	else if (ft_closed(map, i, j - 1) == 0)
		return (0);
	if (map->map_fill[i + 1][j] == '0')
		ft_change_to(map, i + 1, j);
	else if (ft_closed(map, i + 1, j) == 0)
		return (0);
	if (map->map_fill[i - 1][j] == '0')
		ft_change_to(map, i - 1, j);
	else if (ft_closed(map, i - 1, j) == 0)
		return (0);
	return (1);
}

int	ft_closed(t_map *map, int i, int j)
{
	if ((map->map_fill[i][j] == 'N'
		&& (map->player_x != i || map->player_y != j))
		|| (map->map_fill[i][j] == 'E'
		&& (map->player_x != i || map->player_y != j))
		|| (map->map_fill[i][j] == 'W'
		&& (map->player_x != i || map->player_y != j))
		|| (map->map_fill[i][j] == 'S'
		&& (map->player_x != i || map->player_y != j)))
		return (1);
	else if (map->map_fill[i][j] == ' ' || map->map_fill[i][j] == '\t')
		return (0);
	return (1);
}
