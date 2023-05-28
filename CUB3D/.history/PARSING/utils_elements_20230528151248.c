/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:55 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 15:12:48 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_elements_error(char c, char c2, char c3, t_map *map)
{
	if (c == 'N' && c2 == '0' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'S' && c2 == '0' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'W' && c2 == 'E' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'E' && c2 == 'A' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'C' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'F' && is_whitespace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else
		ft_putstr_fd("Error\nElements are not well formated\n", 2);
	ft_clean(map, map->elements);
	exit(0);
}

int	ft_skip_spaces(int i, t_map *map)
{
	int	j;

	j = 0;
	while (is_whitespace(map->cub[i][j]))
		j++;
	return (j);
}

static int	ft_count_elements2(t_map *map, int count, int i, int j)
{
	if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O'
		&& map->cub[i][j + 2] == ' ')
		count++;
	if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O'
		&& map->cub[i][j + 2] == ' ')
		count++;
	if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E'
		&& map->cub[i][j + 2] == ' ')
		count++;
	if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A'
		&& map->cub[i][j + 2] == ' ')
		count++;
	if (map->cub[i][j] == 'C' && map->cub[i][j + 1] == ' ')
		count++;
	if (map->cub[i][j] == 'F' && map->cub[i][j + 1] == ' ')
		count++;
	return (count);
}

int	ft_count_elements(t_map *map, int count)
{
	int	i;
	int	j;

	i = -1;
	while (map->cub[++i])
	{
		j = -1;
		while (map->cub[i][++j])
			count = ft_count_elements2(map, count, i, j);
		if (count == 6)
			return (i);
	}
	return (0);
}
