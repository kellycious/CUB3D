/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:55 by fwong             #+#    #+#             */
/*   Updated: 2023/04/29 18:24:07 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_check_texture(int i, t_map *map, t_elements *elements)
{
	if (ft_strncmp(map->cub[i], "NO", 2) && is_whitespace(map->cub[i + 2]))
	{
		i = ft_skip_spaces(i, map);
		
	}
	if (ft_strncmp(map->cub[i], "SO", 2) && is_whitespace(map->cub[i + 2]))
		elements->no = true;
	if (ft_strncmp(map->cub[i], "WE", 2) && is_whitespace(map->cub[i + 2]))
		elements->no = true;
	if (ft_strncmp(map->cub[i], "EA", 2) && is_whitespace(map->cub[i + 2]))
		elements->no = true;
	if (ft_strncmp(map->cub[i], "C", 1) && is_whitespace(map->cub[i + 1]))
		elements->no = true;
	if (ft_strncmp(map->cub[i], "F", 1) && is_whitespace(map->cub[i + 1]))
		elements->no = true;
}

int	ft_check_
int	ft_skip_spaces(int i, t_map *map)
{
	while (is_whitespace(map->cub[i]))
		i++;
	return (i);
}