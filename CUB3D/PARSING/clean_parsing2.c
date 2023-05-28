/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:53:36 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 19:10:18 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

void	ft_not_closed_and_clean(t_map *map)
{
	ft_putstr_fd("Error\nMap not closed or invalid char in map!\n", 2);
	ft_clean(map, map->elements);
	exit(0);
}

void	ft_map_not_well_formated(t_map *map)
{
	ft_putstr_fd("Error\nMap not well formated!\n", 2);
	ft_clean(map, map->elements);
	exit(0);
}
