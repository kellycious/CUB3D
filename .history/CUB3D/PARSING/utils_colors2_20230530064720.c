/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 06:47:20 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	ft_check_if_only_one_num(char **rgb)
{
	int	i;
	int	j;

	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while (rgb[i][++j] == ' ' || rgb[i][j] == '\t')
			;
		while (rgb[i][++j] >= '0' && rgb[i][j] <= '9')
			;
		while (rgb[i][++j] == ' ' || rgb[i][j] == '\t')
		{
			printf("rgb[%d][%d] = %c\n", i, j, rgb[i][j]);
		
		}
		if (rgb[i][j] != '\0')
			return (0);
	}
	return (1);
}

int	ft_skip_zero(char **rgb, int i, int j)
{
	int	k;
	
	k = 0;
	while (rgb[i][++j] == ' ' || rgb[i][j] == '\t')
	{
		printf("rgb2[%d][%d] = %c\n", i, j, rgb[i][j]);
	}
	while (rgb[i][++j] == '0')
		printf("rgb1[%d][%d] = %c\n", i, j, rgb[i][j]);
	printf("rgsdsdsb[%d][%d] = %c\n", i, j, rgb[i][j - 1]);
	k = j - 1;
	while (rgb[i][++j] == ' ' || rgb[i][j] == '\t')
		;
	if (rgb[i][j] == '\0')
		return (k);
	// if (rgb[i][j] == '\0')
	// {
	// 	ft_putstr_fd("Error\nThere must be 3 numbers in RGB\n", 2);
	// 	ft_clean_rgb(rgb, NULL);
	// 	exit(0);
	// }
	return (j);
}

int	ft_count_numbers(char **rgb, int i, int count)
{
	int	j;

	if (ft_check_if_only_one_num(rgb) == 0)
		return (0);
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
		return (0);
	}
	return (1);
}

void	ft_check_numbers(char **rgb, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (ft_count_numbers(rgb, -1, 0) == 0)
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
