/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:19:53 by fwong             #+#    #+#             */
/*   Updated: 2023/04/28 20:43:09 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	ft_find_map(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	ft_check_elements_error(map, elements);
	i = ft_count_elements(map, elements, 0);
	while (map->cub[i])
	{
		j = 0;
		while (map->cub[i][j] != '1' && map->cub[i][j] != '0')
			j++;
		if (map->cub[i][j] == '1' || map->cub[i][j] == '0')
			return (i);
		i++;
	}
}

void	get_map(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	ft_count_line_map(map, elements);
	i = ft_find_map(map, elements);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	while (map->cub[i])
	{
		map->map[i] = ft_strdup(map->cub[i]);
		i++;
	}
	ft_find_player(map, elements);
	ft_copy_map(map);
}

int	ft_flood_fill(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_fill[++i])
	{
		j = -1;
		while (map->map_fill[i][++j])
		{
			if (ft_check_player(map, i, j))
			{
				ft_change_to_player(map, i, j);
				i = -1;
			}
			else
				return (ft_putstr_fd("Error\nMap not closed\n", 2), exit(0), 0);
		}
	}
	return (1);
}

void	ft_change_to_player(t_map *map, int i, int j)
{
	if (map->map_fill[i][j + 1] == '0')
		map->map_fill[i][j + 1] = 'N';
	if (map->map_fill[i][j - 1] == '0')
		map->map_fill[i][j - 1] = 'N';
	if (map->map_fill[i + 1][j] == '0')
		map->map_fill[i + 1][j] = 'N';
	if (map->map_fill[i - 1][j] == '0')
		map->map_fill[i - 1][j] = 'N';
}
