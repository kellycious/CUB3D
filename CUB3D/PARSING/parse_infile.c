/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:43:11 by fwong             #+#    #+#             */
/*   Updated: 2023/05/19 18:57:15 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	get_cub(t_map *map, char *argv)
{
	int	i;
	int	fd;
	int	size;
	
	if (ft_check_cub_ext(argv) == 1)
		return (exit(0), 0);
	size = ft_count_line_cub(argv, map);
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (ft_putstr_fd("Error\nfd is not correct!\n", 2), close(fd), 0);
	map->cub = ft_calloc(size + 1, sizeof(char *));
	if (!map->cub)
		return (close(fd), 0);
	
	i = 0;
	while (i < size)
		map->cub[i++] = get_next_line(fd);
	map->cub[i] = NULL;
	close(fd);
	ft_remove_nl(map);
	return (1);
}

