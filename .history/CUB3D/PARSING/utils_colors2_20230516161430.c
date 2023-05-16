/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 16:14:30 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_only_numbers(char **rgb, char **rgb_final, t_map *map)
{
	ft_putstr_fd("Error\nOnly numbers are allowed in RGB\n", 2);
	ft_clean_rgb_and_exit(rgb, rgb_final, map);
}

int	ft_not_allowed_in_rgb(int i, int j, char **rgb)
{
	if ((rgb[i][j] > 32 && rgb[i][j] < 48)
		|| (rgb[i][j] > 57 && rgb[i][j] < 127))
		return (1);
	return (0);
}

void	ft_check_numbers(char **rgb, char **rgb_final, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (ft_not_allowed_in_rgb(i, j, rgb))
				ft_only_numbers(rgb, NULL, map);
			j++;
		}
		i++;
	}
}