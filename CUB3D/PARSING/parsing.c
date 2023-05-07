/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:49:57 by fwong             #+#    #+#             */
/*   Updated: 2023/05/06 18:59:11 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_parsing(t_map *map, t_elements *elements, char *argv)
{
	ft_init_struct_map(map);
	if (!get_cub(map, argv))
		exit(0);
	ft_check_elements(map, elements);
	get_map(map, elements);
	ft_flood_fill(map);
	ft_parse_textures(map);
	printf("CACA\n");
	// ft_parse_colors(map);
}
