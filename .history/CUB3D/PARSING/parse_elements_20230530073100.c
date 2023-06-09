/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:08 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 07:30:59 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

// 1st step: check if elements are well formated
void	ft_check_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
			j++;
		if (map->cub[i][j] && map->cub[i][j + 1] && map->cub[i][j + 2])
			ft_assign_elements(map->cub[i][j], map->cub[i][j + 1],
				map->cub[i][j + 2], map);
		i++;
	}
	if (map->elements->no == false || map->elements->so == false
		|| map->elements->we == false || map->elements->ea == false
		|| map->elements->ceiling == false || map->elements->floor == false)
	{
		ft_putstr_fd("Error\nMissing elements\n", 2);
		ft_clean(map, map->elements);
		exit(0);
	}
}

void	ft_assign_elements(char c, char c2, char c3, t_map *map)
{
	if (c == 'N' && c2 == 'O' && is_whitespace(c3)
		&& map->elements->no == false)
		map->elements->no = true;
	else if (c == 'S' && c2 == 'O' && is_whitespace(c3)
		&& map->elements->so == false)
		map->elements->so = true;
	else if (c == 'W' && c2 == 'E' && is_whitespace(c3)
		&& map->elements->we == false)
		map->elements->we = true;
	else if (c == 'E' && c2 == 'A' && is_whitespace(c3)
		&& map->elements->ea == false)
		map->elements->ea = true;
	else if (c == 'C' && is_whitespace(c2) && map->elements->ceiling == false)
		map->elements->ceiling = true;
	else if (c == 'F' && is_whitespace(c2) && map->elements->floor == false)
		map->elements->floor = true;
	else if ((c == 'N' && c2 == 'O' && map->elements->no == true)
		|| (c == 'S' && c2 == 'O' && map->elements->so == true)
		|| (c == 'W' && c2 == 'O' && map->elements->we == true)
		|| (c == 'E' && c2 == 'O' && map->elements->ea == true)
		|| (c == 'C' && map->elements->ceiling == true)
		|| (c == 'F' && map->elements->floor == true))
		ft_elements_error(c, c2, c3, map);
}

void	ft_parse_textures(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->cub[++i])
	{
		j = 0;
		while (map->cub[i][j])
		{
			while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
				j++;
			ft_get_texture(map, i, j);
			j++;
		}		
	}
}

static void	ft_get_texture2(t_map *map, int i, int j)
{
	if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E'
		&& is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->we = ft_strdupy(map->cub[i] + j + 2);
	}
	else if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A'
		&& is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->ea = ft_strdup(map->cub[i] + j + 2);
	}
}

// 3rd step: get the path of the textures
void	ft_get_texture(t_map *map, int i, int j)
{
	if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O'
		&& is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->no = ft_strdup(map->cub[i] + j + 2);
	}
	else if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O'
		&& is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->so = ft_strdup(map->cub[i] + j + 2);
	}
	ft_get_texture2(map, i, j);
}
