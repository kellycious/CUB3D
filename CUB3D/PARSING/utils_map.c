#include "../LIB/cub3d.h"

void	ft_copy_map(t_map *map)
{
	int	i;
	int	j;

	map->map_fill = ft_calloc((map->height + 1), sizeof(char *));
	if (!map->map_fill)
		return (ft_putstr_fd("Error\nMalloc error!\n", 2), exit(0));
	i = -1;
	while (map->map[++i])
		map->map_fill[i] = ft_strdup(map->map[i]);
}

void	ft_count_line_map(t_map *map, t_elements *elements)
{
	int	i;
	int	count;

	i = ft_find_map(map, elements);
	count = 0;
	while (map->cub[i])
	{
		count++;
		i++;
	}
	map->height = count;
}
int	ft_check_players(t_map *map, t_elements *elements)
{
	int		i;
	int		j;
	bool	player;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				if (player == true)
					return (ft_putstr_fd("Error\nToo many players!\n", 2), 0);
				player = true;
			}
			j++;
		}
	}
	return (1);
}

void	ft_find_player(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	i = -1;
	if (!ft_check_players(map, elements))
		exit(0);
	while (++i < map->height)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player_y = i;
				map->player_x = j;
			}
		}
	}
}

int	ft_check_player(t_map *map, int i, int j)
{
	if ((map->map_fill[i][j] == 'N' || map->map_fill[i][j] == 'S'
		|| map->map_fill[i][j] == 'E' || map->map_fill[i][j] == 'W')
		&&
		(((map->map_fill[i][j + 1] >= 9 && map->map_fill[i][j + 1] <= 13)
		|| map->map_fill[i][j + 1] == ' ')
		|| ((map->map_fill[i][j - 1] >= 9 && map->map_fill[i][j - 1] <= 13)
		|| map->map_fill[i][j + 1] == ' ')
		|| ((map->map_fill[i + 1][j] >= 9 && map->map_fill[i + 1][j] <= 13)
		|| map->map_fill[i + 1][j] == ' ')
		|| ((map->map_fill[i - 1][j] >= 9 && map->map_fill[i - 1][j] <= 13)
		|| map->map_fill[i - 1][j] == ' ')))
		return (0);
	return (1);
}

