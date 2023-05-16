/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 00:50:58 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

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