#include "../LIB/cub3d.h"

int ft_count_line_cub(char *argv, t_map *map)
{
	int	count;
	int	fd;
	char	*map;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (0);
	map = get_next_line(fd);
	if (map == NULL)
		return(close(fd), free(map), ft_error(map), exit(0), 0);
	if (!map)
		return (close(fd), exit(0), 0);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		count++;
	}
	close(fd);
	map->height = count;
	return (count);
}

int	ft_remove_nl(t_map *map)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '\n' || map->map[i][j] == '\r')
				map->map[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_cub_ext(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u'
		&& argv[i - 3] == 'c' && argv[i - 4] == '.')
		return (1);
	return (ft_putstr_fd("Error\nFile should be .cub extension!\n", 2), 0);
}