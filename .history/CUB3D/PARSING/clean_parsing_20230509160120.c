/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:11:39 by fwong             #+#    #+#             */
/*   Updated: 2023/05/09 16:01:20 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_clean_colors(char **rgb, char **rgb_final)
{
	int	i;

	i = -1;
	if (rgb)
	{
		while (rgb[++i])
			free(rgb[i]);
		free(rgb);
	}
	i = -1;
	if (rgb_final)
	{
		while (rgb_final[++i])
			free(rgb_final[i]);
		free(rgb_final);
	}
	ft_elements_error('0', '0', '0');
}
void	ft_clean(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->map)
		ft_free_map(map->map);
	if (map->map_fill)
		ft_free_map(map->map_fill);
	if (map->cub)
		ft_free_map(map->cub);
	free(map)
	exit(0);
}

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}