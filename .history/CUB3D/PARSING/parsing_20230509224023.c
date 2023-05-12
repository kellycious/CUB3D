/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:49:57 by fwong             #+#    #+#             */
/*   Updated: 2023/05/09 22:40:23 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_parsing(t_map *map, t_elements *elements, char *argv)
{
	(void)elements;
	ft_init_struct_map(map);
	if (!get_cub(map, argv))
		exit(0);
	ft_check_elements(map, elements);
	while ()
	ft_clean(map, elements);
	// get_map(map, elements);
	// ft_flood_fill(map);
	// ft_check_closed(map);
	// ft_parse_textures(map);
	// ft_parse_colors(map);
	// printf("map->no = %s\n", map->no);
	// printf("map->so = %s\n", map->so);
	// printf("map->we = %s\n", map->we);
	// printf("map->ea = %s\n", map->ea);
	// printf("player_x = %d\n", map->player_x);
	// printf("player_y = %d\n", map->player_y);
	// printf("map->floor_r = %d\n", map->floor_r);
	// printf("map->floor_g = %d\n", map->floor_g);
	// printf("map->floor_b = %d\n", map->floor_b);
	// printf("map->ceiling_r = %d\n", map->ceiling_r);
	// printf("map->ceiling_g = %d\n", map->ceiling_g);
	// printf("map->ceiling_b = %d\n", map->ceiling_b);
}
