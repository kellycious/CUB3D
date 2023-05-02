/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/04/30 14:41:41 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

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
			if (map->cub[i][j] == 'C')
				ft_parse_colors(i, j, map, elements);
			if (map->cub[i][j] == 'F')
				count++;
		}
	}
}

void	ft_parse_colors(int i, int j, t_map *map, t_elements *elements)
{
	while (map->cub[i][++j])
	{
		if (map->cub[i][j] == 'C')
			ft_parse_color_c(map, elements, i, j);
		if (map->cub[i][j] == 'F')
			ft_parse_color_f(map, elements, i, j);
	}
}
