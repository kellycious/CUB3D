/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 01:09:00 by fwong            ###   ########.fr       */
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
	printf("rgb[%d][%d] = %c\n", i, j, rgb[i][j]);
	if (rgb[i][j] != ' ')
		return (1);
	if (rgb[i][j] != '\t')
		return (1);
	if (rgb[i][j] != '\0')
		return (1);
	if (rgb[i][j] != ',')
		return (1);
	return (0);
}