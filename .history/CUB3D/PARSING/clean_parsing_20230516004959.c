/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:11:39 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 00:49:59 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_clean(t_map *map, t_elements *elements)
{
	if (map->no != NULL)
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
	free(map);
	free(elements);
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

void	ft_clean_rgb(char **rgb, char **rgb_final, t_map *map)
{
	int	i;

	i = -1;
	if (rgb)
	{
		while (++i < 3)
			free(rgb[i]);
		free(rgb);
	}
	i = -1;
	if (rgb_final)
	{
		while (++i < 3)
			if (rgb_final[i])
				free(rgb_final[i]);
		free(rgb_final);
	}
	ft_clean(map, map->elements);
}

void	ft_only_numbers(char **rgb, char **rgb_final, t_map *map)
{
	ft_putstr_fd("Error\nOnly numbers for colors\n", 2);
	ft_clean_rgb(rgb, rgb_final, map);
}

int	ft_not_allowed_in_rgb(int i, int j, char **rgb)
{
	if (!(rgb[i][j] >= '0' && rgb[i][j] <= '9')
	|| !(rgb[i][j] == ' ')
	|| !(rgb[i][j] == '\t')
	|| !(rgb[i][j] == '\0')
	|| !(rgb[i][j] == ','))
		return (1);
	return (0);
}
