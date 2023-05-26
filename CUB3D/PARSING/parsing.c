/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:49:57 by fwong             #+#    #+#             */
/*   Updated: 2023/05/26 22:16:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_parsing(t_map *map, t_elements *elements, int ac, char *argv)
{
	bool	player;
	int i = 0;

	player = false;
	ft_init_struct_map(map);
	ft_init_struct_elements(elements);
	map->elements = elements;
	if (get_cub(map, ac, argv) == 0)
		return (ft_clean(map, elements), exit(0));
	ft_check_elements(map);
	get_map(map, elements);
	filler_map(map);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	ft_flood_fill(map, player);
	ft_check_closed(map);
	ft_parse_textures(map);
	ft_parse_colors(map);
}
