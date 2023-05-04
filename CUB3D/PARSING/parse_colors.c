/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/05/04 21:21:03 by fwong            ###   ########.fr       */
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
	ft_parse_c(i, 0, map, elements);
}

void	ft_parse_c(int k, int l, t_map *map, t_elements *elements)
{
	int		i;
	int		j;
	char	*nbr;
	char	**rgb;

	i = 0;
	j = 0;
	nbr = ft_strdup(map->cub[i] + 1);
	rgb = ft_split(nbr, ',');
	ft_assign_rgb(0, 0, l, rgb);
	while (rgb[i])
	{
		while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
		while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
		{
			if (j > 3)
				ft_elements_error('0', '0', '0');
			color[j] = rgb[i][l];
			j++;
			l++;
		}
	}
	
}

void	ft_assign_rgb(int i, int j, int l, char **rgb)
{
	char	*color[3];
	
	while (rgb[i])
	{
		while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
		while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
		{
			if (j > 3)
				ft_elements_error('0', '0', '0');
			color[j] = rgb[i][l];
			j++;
			l++;
		}
}
