/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:55 by fwong             #+#    #+#             */
/*   Updated: 2023/05/26 17:50:17 by fwong            ###   ########.fr       */
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
	ft_clean(map, NULL);
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

int	ft_check_other_char(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'W' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'N' && map->map[i][j] != 'S')
				return (ft_putstr_fd("Error\ninvalid char in map\n",
					2), ft_clean(map, map->elements), exit(0), 0);
			j++;
		}
		i++;
	}
	return (0);
}

