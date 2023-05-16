/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 02:19:55 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_only_numbers(char **rgb, char **rgb_final, t_map *map)
{
	ft_clean_rgb(rgb, rgb_final, map);
	ft_elements_error('0', '0', '0', map);
}

int	ft_not_allowed_in_rgb(int i, int j, char **rgb)
{
	printf("rgb[%d][%d] = %c\n", i, j, rgb[i][j]);
	if ((rgb[i][j] > 32 && rgb[i][j] < 48)
		|| (rgb[i][j] > 57 && rgb[i][j] < 127))
		return (1);
	return (0);
}

void	ft_check_rgb(char **rg)