/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 20:49:47 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_only_numbers(char **rgb, t_map *map)
{
	ft_putstr_fd("Error\nOnly numbers are allowed in RGB\n", 2);
	ft_clean_rgb_and_exit(rgb, NULL, map);
}

int	ft_not_allowed_in_rgb(int i, int j, char **rgb)
{
	if ((rgb[i][j] > 32 && rgb[i][j] < 48)
		|| (rgb[i][j] > 57 && rgb[i][j] < 127))
		return (1);
	return (0);
}
