/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:20:49 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 07:16:21 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_skip_spaces_rgb(char **rgb, int i, int j, t_map *map)
{
	while (rgb[i][j])
	{
		if (rgb[i][j] != ' ' && rgb[i][j] != '\t')
			ft_elements_error('0', '0', '0', map);
		j++;
	}
}

int	ft_assign_rgb_c(t_map *map, char **rgb_final)
{
	map->ceiling_r = ft_atoi(rgb_final[0]);
	map->ceiling_g = ft_atoi(rgb_final[1]);
	map->ceiling_b = ft_atoi(rgb_final[2]);
	if (map->ceiling_r < 0 || map->ceiling_r > 255)
		return (0);
	if (map->ceiling_g < 0 || map->ceiling_g > 255)
		return (0);
	if (map->ceiling_b < 0 || map->ceiling_b > 255)
		return (0);
	return (1);
}

int	ft_assign_rgb_f(t_map *map, char **rgb_final)
{
	map->floor_r = ft_atoi(rgb_final[0]);
	map->floor_g = ft_atoi(rgb_final[1]);
	map->floor_b = ft_atoi(rgb_final[2]);
	if (map->floor_r < 0 || map->floor_r > 255)
		return (0);
	if (map->floor_g < 0 || map->floor_g > 255)
		return (0);
	if (map->floor_b < 0 || map->floor_b > 255)
		return (0);
	return (1);
}

void	ft_get_rgb_final(char **rgb_final, char **rgb)
{
	int		i;
	int		j;
	int		k;
	bool	number;

	i = 0;
	number = false;
	while (rgb[i])
	{
		j = 0;
		k = 0;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		while (rgb[i][j] == '0')
			j++;
		j--;
		while (rgb[i][j] >= '0' && rgb[i][j] <= '9')
		{
			number = true;
			rgb_final[i][k] = rgb[i][j];
			j++;
			k++;
		}
		i++;
	}
	if (number == false)
		exit(0);
}

int	ft_above_3_digits(char **rgb, char **rgb_final, int j, t_map *map)
{
	if (j > 3)
	{
		ft_putstr_fd("Error\nToo many digits for colors\n", 2);
		ft_clean_rgb_and_exit(rgb, rgb_final, map);
	}
	j++;
	return (j);
}
