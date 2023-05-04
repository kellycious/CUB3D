/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/05/04 17:21:55 by fwong            ###   ########.fr       */
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
				ft_check_and_parse_c(i, j + 1, map, elements);
			if (map->cub[i][j] == 'F')
				ft_check_and_parse_f(i, j + 1, map, elements);
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
	int		count;
	int		color[3];
	char	*nbr;

	nbr = ft_strdup(map->cub[i] + 1);
	
	if (count != 3)
		ft_elements_error('0', '0', '0');
	elements->c = ft_create_trgb(0, color[0], color[1], color[2]);
}
