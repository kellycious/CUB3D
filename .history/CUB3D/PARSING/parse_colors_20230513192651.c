/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:00:40 by fwong             #+#    #+#             */
/*   Updated: 2023/05/13 19:26:51 by fwong            ###   ########.fr       */
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
			if (map->cub[i][j] == 'C' && map->cub[i][j + 1] == ' ')
				ft_check_and_parse_c(i, j, map);
			if (map->cub[i][j] == 'F' && map->cub[i][j + 1] == ' ')
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
		ft_elements_error('0', '0', '0');
	while (map->cub[i][k])
	{
		if (map->cub[i][k] == ',')
			count++;
		k++;
	}
	if (count != 2)
		ft_elements_error('0', '0', '0');
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
	rgb_final = ft_get_rgb(0, 0, 0, rgb);
	if (!ft_assign_rgb_c(map, rgb))
	{
		ft_clean_rgb(rgb, rgb_final);
		ft_elements_error('0', '0', '0');
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
	rgb_final = ft_get_rgb(0, 0, 0, rgb);
	if (!ft_assign_rgb_f(map, rgb))
	{
		printf("CACA\n");
		ft_clean_rgb(rgb, rgb_final);
		ft_elements_error('0', '0', '0');
	}
	ft_clean_rgb(rgb, rgb_final);
}

char	**ft_get_rgb(int i, int j, int l, char **rgb)
{
	char	**rgb_final;
	
	rgb_final = ft_calloc(3, sizeof(char *));
	while (i < 3)
	{
		l = 0;
		j = 0;
		while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
		if (rgb[i][l] < '0' || rgb[i][l] > '9')
			ft_clean_colors(rgb, rgb_final);
		while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
		{
			if (j > 3)
				ft_clean_colors(rgb, rgb_final);
			j++;
			l++;
		}
		rgb_final[i] = ft_calloc(j + 1, sizeof(char));
		ft_skip_spaces_rgb(rgb, i, l);
		i++;
	}
	ft_get_rgb_final(rgb_final, rgb);
	return (rgb_final);
}


