/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 07:09:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_parse_colors(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->cub[++i])
	{
		j = -1;
		while (map->cub[i][++j])
		{
			if (map->cub[i][j] == 'C' && is_whitespace(map->cub[i][j + 1]))
				ft_check_and_parse_c(i, j, map);
			if (map->cub[i][j] == 'F' && is_whitespace(map->cub[i][j + 1]))
				ft_check_and_parse_c(i, j, map);
		}
	}
}

void	ft_check_and_parse_c(int i, int j, t_map *map)
{
	int	k;
	int	count;

	k = j;
	count = 0;
	k++;
	while (map->cub[i][k] == ' ' || map->cub[i][k] == '\t')
		k++;
	if (map->cub[i][k] < '0' && map->cub[i][k] > '9')
		ft_elements_error('0', '0', '0', map);
	while (map->cub[i][k])
	{
		if (map->cub[i][k] == ',')
			count++;
		k++;
	}
	if (count != 2)
		ft_elements_error('0', '0', '0', map);
	if (map->cub[i][j] == 'C')
		ft_parse_c(i, map);
	if (map->cub[i][j] == 'F')
		ft_parse_f(i, map);
}

void	ft_parse_c(int i, t_map *map)
{
	char	*nbr;
	char	**rgb;
	char	**rgb_final;

	nbr = ft_strdup(map->cub[i] + 1);
	rgb = ft_split(nbr, ',');
	if (nbr)
		free(nbr);
	rgb_final = ft_get_rgb(0, 0, rgb, map);
	if (ft_assign_rgb_c(map, rgb) == 0)
	{
		ft_putstr_fd("Error\nColors need to be set between 0 and 255\n", 2);
		ft_clean_rgb_and_exit(rgb, rgb_final, map);
	}
	ft_clean_rgb(rgb, rgb_final);
}

void	ft_parse_f(int i, t_map *map)
{
	char	*nbr;
	char	**rgb;
	char	**rgb_final;

	while (map->cub[i][0] == ' ' || map->cub[i][0] == '\t')
		i++;
	nbr = ft_strdup(map->cub[i] + 1);
	rgb = ft_split(nbr, ',');
	if (nbr)
		free(nbr);
	rgb_final = ft_get_rgb(0, 0, rgb, map);
	if (ft_assign_rgb_f(map, rgb) == 0)
	{
		ft_putstr_fd("Error\nColors need to be set between 0 and 255\n", 2);
		ft_clean_rgb_and_exit(rgb, rgb_final, map);
	}
	ft_clean_rgb(rgb, rgb_final);
}

char	**ft_get_rgb(int j, int l, char **rgb, t_map *map)
{
	char	**rgb_final;
	int		i;

	i = -1;
	ft_check_numbers(rgb, map);
	rgb_final = ft_calloc(4, sizeof(char *));
	while (rgb[++i])
	{
		l = 0;
		j = 1;
		while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
		while (rgb[i][l] == '0')
			l++;
		while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
		{
			j = ft_above_3_digits(rgb, rgb_final, j, map);
			l++;
		}
		rgb_final[i] = ft_calloc(j + 2, sizeof(char));
	}
	rgb_final[i] = 0;
	ft_get_rgb_final(rgb_final, rgb);
	return (rgb_final);
}
