/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 05:47:28 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static int	ft_check_if_only_one_num(char **rgb)
{
	int	i;
	int	j;

	
}

static int	ft_skip_zero(char **rgb, int i, int j)
{
	while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
		j++;
	while (rgb[i][j] == '0')
		j++;
	if (rgb[i][j] == '\0')
	{
		ft_putstr_fd("Error\nThere must be 3 numbers in RGB\n", 2);
		ft_clean_rgb(rgb, NULL);
		exit(0);
	}
	return (j);
}

int	ft_count_numbers(char **rgb, int i, int count)
{
	int	j;

	while (rgb[++i])
	{
		j = -1;
		j = ft_skip_zero(rgb, i, j);
		while (rgb[i][++j] != '\0')
		{
			if (rgb[i][j] >= '0' && rgb[i][j] <= '9')
			{
				count++;
				break ;
			}
		}
	}
	if (count != 3)
	{
		ft_putstr_fd("Error\nThere must be 3 numbers in RGB\n", 2);
		ft_clean_rgb(rgb, NULL);
		return (1);
	}
	return (0);
}

void	ft_check_numbers(char **rgb, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (ft_count_numbers(rgb, -1, 0) == 1)
		return (ft_clean(map, map->elements), exit(0));
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (ft_not_allowed_in_rgb(i, j, rgb))
				ft_only_numbers(rgb, map);
			j++;
		}
		i++;
	}
}
