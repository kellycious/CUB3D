/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:19:53 by fwong             #+#    #+#             */
/*   Updated: 2023/05/06 19:01:24 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	ft_find_map(t_map *map, t_elements *elements)
{
	int	i;
	int	j;
	(void)elements;

	i = ft_count_elements(map, 0);
	while (i < map->height)
	{
		j = 0;
		while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
		{
			if (!(map->cub[i][j] == ' ' || map->cub[i][j] == '\t'
				|| map->cub[i][j] == '1' || map->cub[i][j] == '0'))
				return (printf("JE LE SAVAIS"), ft_elements_error('0', '0', '0'), 0);
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
	i = ft_find_map(map, elements);
	j = 0;
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	while (map->cub[i])
	{
		map->map[j] = ft_strdup(map->cub[i]);
		i++;
		j++;
	}
	ft_find_player(map);
	ft_copy_map(map);
}

int	ft_flood_fill(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_fill[i])
	{
		j = -1;
		printf("%s\n", map->map_fill[0]);
		printf("%s\n", map->map_fill[1]);
		printf("%s\n\n", map->map_fill[2]);
		while (map->map_fill[i][++j])
		{
			if (ft_check_player(map, i, j) == 1)
			{
				if (ft_change_to_player(map, i, j) == 0)
					return (ft_putstr_fd("Error\nMap not closed\n", 1),
					ft_clean(map), 0);
				i = 0;
			}
		}
		i++;
	}
	return (1);
}

int	ft_change_to_player(t_map *map, int i, int j)
{
	if (map->map_fill[i][j + 1] == '0')
		map->map_fill[i][j + 1] = 'Z';
	else if (!ft_closed(map, i, j + 1))
		return (0);
	if (map->map_fill[i][j - 1] == '0')
		map->map_fill[i][j - 1] = 'Z';
	else if (!ft_closed(map, i, j - 1))
		return (0);
	if (map->map_fill[i + 1][j] == '0')
		map->map_fill[i + 1][j] = 'Z';
	else if (!ft_closed(map, i + 1, j))
		return (0);
	if (map->map_fill[i - 1][j] == '0')
		map->map_fill[i - 1][j] = 'Z';
	else if (!ft_closed(map, i - 1, j))
		return (0);
	printf("%s\n", map->map_fill[0]);
	printf("%s\n", map->map_fill[1]);
	printf("%s\n\n", map->map_fill[2]);
	return (1);
}

int	ft_closed(t_map *map, int i, int j)
{
	if ((map->map_fill[i][j] == 'N'
		&& (map->player_x != i && map->player_y != j))
		|| (map->map_fill[i][j] == 'E' 
		&& (map->player_x != i && map->player_y != j))
		|| (map->map_fill[i][j] == 'W'
		&& (map->player_x != i && map->player_y != j))
		|| (map->map_fill[i][j] == 'S'
		&& (map->player_x != i && map->player_y != j)))
		return (0);
	else if ((map->map_fill[i][j] == 'N'
		&& (map->player_x == i && map->player_y == j))
		|| (map->map_fill[i][j] == 'E' 
		&& (map->player_x == i && map->player_y == j))
		|| (map->map_fill[i][j] == 'W'
		&& (map->player_x == i && map->player_y == j))
		|| (map->map_fill[i][j] == 'S'
		&& (map->player_x == i && map->player_y == j)))
		return (1);
	else if (map->map_fill[i][j] != '1')
		return (0);
	return (1);
}
