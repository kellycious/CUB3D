/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 02:26:41 by fwong            ###   ########.fr       */
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

int	ft_check_rgb(char **rgb, char **rgb_final, int i, int j)
{
	while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
	if (rgb[i][j] < '0' || rgb[i][j] > '9')
		return (0);
	while (rgb[i][j] >= '0' && rgb[i][j] <= '9')
	{
		if (j > 3)
			return (0);
		j++;
	}
	if (ft_not_allowed_in_rgb(i, j, rgb) == 1)
		return (0);
	if (ft_skip_spaces_rgb(rgb, i, j) == 2)
		return (2);
}