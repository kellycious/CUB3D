/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:43:11 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 19:28:48 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static int	check_arg(int ac)
{
	if (ac == 2)
		return (1);
	return (ft_putstr_fd("Error\ninvalid nb of arg\n", 2), 0);
}

int	get_cub(t_map *map, int ac, char *argv)
{
	int	i;
	int	fd;
	int	size;

	if (check_arg(ac) == 1)
	{
		if (ft_check_cub_ext(argv) == 1)
			return (ft_clean(map, map->elements), exit(0), 0);
		size = ft_count_line_cub(argv, map);
		fd = open(argv, O_RDONLY);
		if (fd <= -1)
			return (ft_putstr_fd("Error: does your .cub file exist ?\n", 2),
				close(fd), 0);
		map->cub = ft_calloc(size + 1, sizeof(char *));
		if (!map->cub)
			return (close(fd), 0);
		i = 0;
		while (i < size)
			map->cub[i++] = get_next_line(fd);
		map->cub[i] = NULL;
		close(fd);
		return (ft_remove_nl(map), 1);
	}
	return (0);
}
