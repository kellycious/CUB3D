/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:49:43 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/28 17:10:15 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB/cub3d.h"

static void	init_struct(t_map *map)
{
	t_mlx		*mlxy;
	t_rayc		*ray;
	t_player	*player;
	t_texture	*texture;
	int			i;

	i = 0;
	while (i < 4)
	{
		mlxy = ft_calloc(sizeof(t_mlx), 1);
		map->txt[i] = *mlxy;
		free(mlxy);
		i++;
	}
	ray = ft_calloc(sizeof(t_rayc), 1);
	map->ray = *ray;
	texture = ft_calloc(sizeof(t_texture), 1);
	map->tex = *texture;
	player = ft_calloc(sizeof(t_player), 1);
	map->player = player;
	free(ray);
	free(texture);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_elements	*elements;

	map = ft_calloc(sizeof(t_map), 1);
	elements = ft_calloc(sizeof(t_elements), 1);
	ft_parsing(map, elements, ac, av[1]);
	init_struct(map);
	render_map(map);
	exit_game(map);
	return (0);
}
