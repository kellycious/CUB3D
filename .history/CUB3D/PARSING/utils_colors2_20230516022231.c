/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:50:14 by fwong             #+#    #+#             */
/*   Updated: 2023/05/16 02:22:31 by fwong            ###   ########.fr       */
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

void	ft_check_rgb(char **rgb, char **rgb_final, int i, int j)
{
	while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
	if (rgb[i][l] < '0' || rgb[i][l] > '9')
		ft_clean_rgb(rgb, rgb_final, map);
	while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
	{
		j = ft_above_3_digits(rgb, rgb_final, j, map);
		l++;
	}
	if (ft_not_allowed_in_rgb(i, l, rgb) == 1)
		ft_only_numbers(rgb, rgb_final, map);
	ft_skip_spaces_rgb(rgb, i, l, map);
}