/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:43:11 by fwong             #+#    #+#             */
/*   Updated: 2023/04/29 17:50:52 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

int	get_cub(t_map *map, char *argv)
{
	int	i;
	int	fd;
	int	size;

	size = ft_count_line_cub(argv, map);
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (ft_putstr_fd("Error\nfd is not correct!\n", 2), close(fd), 0);
	map->cub = ft_calloc(size + 1, sizeof(char *));
	if (!map->cub)
		return (close(fd), 0);
	i = 0;
	while (i < size + 1)
		map->cub[i++] = get_next_line(fd);
	close(fd);
	ft_remove_nl(map);
	return (1);
}

int	ft_check_textures(t_map *map)
{
	int	i;
	int	j;
	
	i = -1;
	j = -1;
	while (map->cub[++i])
	{
		while (map->cub[i][++j])
		{
			if (map->cub[i] == 'N' && map->cub[i + 1] == 'O')
				ft_check_textures()
		}
	}
}
