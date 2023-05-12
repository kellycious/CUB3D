/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:08 by fwong             #+#    #+#             */
/*   Updated: 2023/05/09 23:14:04 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

// 1st step: check if elements are well formated
void	ft_check_elements(t_map *map, t_elements *elements)
{
	int	i;
	int	j;
	(void)elements;
	
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
			j++;
		ft_assign_elements(map->cub[i][j], map->cub[i][j + 1], map->cub[i][j + 2], elements);
		i++;
	}
}

void	ft_not_elements(char c, char c2, char c3)
{
	if (!((c == 'N' && c2 == 'O' && is_whitespace(c3))
		|| (c == 'S' && c2 == 'O' && is_whitespace(c3))
		|| (c == 'W' && c2 == 'E' && is_whitespace(c3))
		|| (c == 'E' && c2 == 'A' && is_whitespace(c3))
		|| (c == 'C' && is_whitespace(c2)) || (c == 'F' && is_whitespace(c2))
		|| (c == ' ') || (c == '\t') || (c == '\n')))
	{
		ft_putstr_fd("Error\nFormat of infile is wrong\n", 2);
		exit(0);
	}
}
void	ft_assign_elements(t_map *map, t_elements *element, int i, int j)
{
	if (ft_strncmp(map->cub[i] + j, "NO ", 3) && element->no == false)
		element->no = true;
	else if (c == 'S' && c2 == 'O' && is_whitespace(c3) && element->so == false)
		element->so = true;
	else if (c == 'W' && c2 == 'E' && is_whitespace(c3) && element->we == false)
		element->we = true;
	else if (c == 'E' && c2 == 'A' && is_whitespace(c3) && element->ea == false)
		element->ea = true;
	else if (c == 'C' && is_whitespace(c3) && element->ceiling == false)
		element->ceiling = true;
	else if (c == 'F' && is_whitespace(c3) && element->floor == false)
		element->floor	= true;
	else if ((c == 'N' && c2 == 'O' && element->no == true)
			|| (c == 'S' && c2 == 'O' && element->so == true)
			|| (c == 'W' && c2 == 'O' && element->we == true)
			|| (c == 'E' && c2 == 'O' && element->ea == true)
			|| (c == 'C' && element->ceiling == true)
			|| (c == 'F' && element->floor == true))
				ft_elements_error(c, c2, c3);
}

void	ft_parse_textures(t_map *map)
{
	int	i;
	int	j;
	
	i = -1;
	while (map->cub[++i])
	{
		j = 0;
		while (map->cub[i][j])
		{
			while(map->cub[i][j] == ' ' || map->cub[i][j] == '\t')
				j++;
			ft_get_texture(map, i, j);
			j++;
		}		
	}
}

// 3rd step: get the path of the textures
void	ft_get_texture(t_map *map, int i, int j)
{
	if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O' && is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->no = ft_strdup(map->cub[i] + j + 2);
	}
	else if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O' && is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->so = ft_strdup(map->cub[i] + j + 2);
	}
	else if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E' && is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->we	= ft_strdup(map->cub[i] + j + 2);
	}
	else if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A' && is_whitespace(map->cub[i][j + 2]))
	{
		while (map->cub[i][j + 2] == ' ' || map->cub[i][j + 2] == '\t')
			j++;
		map->ea = ft_strdup(map->cub[i] + j + 2);
	}
}

int	ft_count_elements(t_map *map, int count)
{
	int	i;
	int	j;

	i = -1;
	while (map->cub[++i])
	{
		j = -1;
		while (map->cub[i][++j])
		{  
			if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O' && map->cub[i][j + 2] == ' ')
				count++;
			if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O' && map->cub[i][j + 2] == ' ')
				count++;
			if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E' && map->cub[i][j + 2] == ' ')
				count++;
			if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A' && map->cub[i][j + 2] == ' ')
				count++;
			if (map->cub[i][j] == 'C' && map->cub[i][j + 1] == ' ')
				count++;
			if (map->cub[i][j] == 'F' && map->cub[i][j + 1] == ' ')
				count++;
		}
		if (count == 6)
			return (i + 1);
	}
	return (0);
}
