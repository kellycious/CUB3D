#include "../LIB/cub3d.h"

void	ft_check_elements(t_map *map, t_elements *elements)
{
	int	i;
	int	j;
	
	i = -1;
	j = -1;
	while (map->cub[++i])
	{
		while (map->cub[i][++j])
		{
			if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O')
				elements->no = true;
			if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O')
				elements->so = true;
			if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E')
				elements->we = true;
			if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A')
				elements->ea = true;
			if (map->cub[i][j] == 'C')
				elements->ceiling = true;
			if (map->cub[i][j] == 'F')
				elements->floor	= true;
		}
	}
}

int	ft_check_elements_error(t_map *map, t_elements *elements)
{
	ft_check_elements(map, elements);
	if (elements->no == false)
		ft_putstr_fd("Error\nNo north texture!\n", 2);
	if (elements->so == false)
		ft_putstr_fd("Error\nNo south texture!\n", 2);
	if (elements->we == false)
		ft_putstr_fd("Error\nNo west texture!\n", 2);
	if (elements->ea == false)
		ft_putstr_fd("Error\nNo east texture!\n", 2);
	if (elements->ceiling == false)
		ft_putstr_fd("Error\nNo ceiling color!\n", 2);
	if (elements->floor == false)
		ft_putstr_fd("Error\nNo floor color!\n", 2);
	if (elements->no == true && elements->so == true && elements->we == true
		&& elements->ea == true && elements->ceiling == true
		&& elements->floor == true)
		return (1);
	return (exit(0), 0);
}

int	ft_count_elements(t_map *map, t_elements *elements, int count)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map->cub[++i])
	{
		while (map->cub[i][++j])
		{
			if (map->cub[i][j] == 'N' && map->cub[i][j + 1] == 'O')
				count++;
			if (map->cub[i][j] == 'S' && map->cub[i][j + 1] == 'O')
				count++;
			if (map->cub[i][j] == 'W' && map->cub[i][j + 1] == 'E')
				count++;
			if (map->cub[i][j] == 'E' && map->cub[i][j + 1] == 'A')
				count++;
			if (map->cub[i][j] == 'C')
				count++;
			if (map->cub[i][j] == 'F')
				count++;
		}
		if (count == 6)
			return (i + 1);
	}
}
