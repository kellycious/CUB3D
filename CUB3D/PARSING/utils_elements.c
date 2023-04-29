/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:08 by fwong             #+#    #+#             */
/*   Updated: 2023/04/28 20:44:40 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_check_elements(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map->cub[++i])
	{
		while (map->cub[i][++j])
		{
			ft_assign_elements(map->cub[i][j],
				map->cub[i][j + 1], map->cub[i][j + 2], elements);
		}
	}
}

int	ft_check_elements_error(t_map *map, t_elements *elements)
{
	ft_check_elements(map, elements);
	if (elements->no == false)
		ft_putstr_fd("Error\nNo north texture!\n", 2);
	if (elements->so == false)
		ft_putstr_fd("Error\nNo south texture!\n", 2);
	if (elements->we == false)
		ft_putstr_fd("Error\nNo west texture!\n", 2);
	if (elements->ea == false)
		ft_putstr_fd("Error\nNo east texture!\n", 2);
	if (elements->ceiling == false)
		ft_putstr_fd("Error\nNo ceiling color!\n", 2);
	if (elements->floor == false)
		ft_putstr_fd("Error\nNo floor color!\n", 2);
	if (elements->no == true && elements->so == true && elements->we == true
		&& elements->ea == true && elements->ceiling == true
		&& elements->floor == true)
		return (1);
	return (exit(0), 0);
}

int	ft_count_elements(t_map *map, t_elements *elements, int count)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map->cub[++i])
	{
		while (map->cub[i][++j])
		{
			if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O')
				count++;
			if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O')
				count++;
			if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E')
				count++;
			if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A')
				count++;
			if (map->cub[i][j] == 'C')
				count++;
			if (map->cub[i][j] == 'F')
				count++;
		}
		if (count == 6)
			return (i + 1);
	}
}

void	ft_assign_elements(char c, char c2, char c3, t_elements *elements)
{
	if (c == 'N' && c2 == 'O' && is_whitespace(c3))
		elements->no = true;
	if (c == 'S' && c2 == 'O' && is_whitespace(c3))
		elements->so = true;
	if (c == 'W' && c2 == 'E' && is_whitespace(c3))
		elements->we = true;
	if (c == 'E' && c2 == 'A' && is_whitespace(c3))
		elements->ea = true;
	if (c == 'C' && is_whitespace(c3))
		elements->ceiling = true;
	if (c == 'F' && is_whitespace(c3))
		elements->floor = true;
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
