#include "../LIB/cub3d.h"

int get_cub(t_map *map, char *argv)
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
