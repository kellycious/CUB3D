/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:55 by fwong             #+#    #+#             */
/*   Updated: 2023/04/30 13:57:37 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_elements_error(char c, char c2, char c3)
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


int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}