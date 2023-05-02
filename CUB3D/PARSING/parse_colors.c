/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/05/02 16:42:08 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_count_elements(t_map *map, t_elements *elements, int count)
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
				ft_check_and_parse_c(i, j, map, elements);
			if (map->cub[i][j] == 'F')
				ft_check_and_parse_f(i, j, map, elements);
		}
	}
}

void	ft_check_and_parse_c(int i, int j, t_map *map, t_elements *elements)
{
	int	k;
	int	count;

	k = j;
	count = 0;
	while (map->cub[i][k] == ' ' || map->cub[i][k] == '\t')
		k++;
	k++;
	if (map->cub[i][k] < '0' || map->cub[i][k] > '9')
		ft_elements_error('0', '0', '0');
	while (map->cub[i][k])
	{
		if (map->cub[i][k] == ',')
			count++;
		k++;
	}
	if (count != 2)
		ft_elements_error('0', '0', '0');
	k = j;
	ft_parse_c(i, k, map, elements);
}

void	ft_parse_c(int i, int k, t_map *map, t_elements *elements)
{
	int	j;
	int	count;
	int	color[3];

	j = k;
	count = 0;
	while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
		j++;
	j++;
	while (map->cub[i][j])
	{
		if (map->cub[i][j] >= '0' && map->cub[i][j] <= '9')
		{
			color[count] = ft_atoi(&map->cub[i][j]);
			while (map->cub[i][j] >= '0' && map->cub[i][j] <= '9')
				j++;
			count++;
		}
		j++;
	}
	if (count != 3)
		ft_elements_error('0', '0', '0');
	elements->c = ft_create_trgb(0, color[0], color[1], color[2]);
}
