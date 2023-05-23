#include "../LIB/cub3d.h"

int ft_count_line_cub(char *argv, t_map *map)
{
	int count;
	int fd;
	char *mappy;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= -1)
		return (0);
	mappy = get_next_line(fd);
	if (mappy == NULL)
		return (close(fd), free(mappy), ft_clean(map, map->elements), 0);
	if (!mappy)
		return (close(fd), exit(0), 0);
	while (mappy)
	{
		free(mappy);
		mappy = get_next_line(fd);
		count++;
	}
	close(fd);
	map->height = count;
	return (count);
}

int ft_remove_nl(t_map *map)
{
	int i;
	size_t j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->cub[i][j] == ' ')
		{
			if (map->cub[i][j] == '\n' || map->cub[i][j] == '\r')
			{
				map->cub[i][j] = '\0';
				map->cub[i][j + 1] = '\0';
				map->cub[i][j + 2] = '\0';
			}
			j++;
		}
		while (map->cub[i][j])
		{
			if (map->cub[i][j] == '\n' || map->cub[i][j] == '\r')
				map->cub[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_cub_ext(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c' && argv[i - 4] == '.')
		return (0);
	return (ft_putstr_fd("Error: File should have .cub extension!\n", 2), 1);
}

void ft_init_struct_map(t_map *map)
{
	map->n = 0;
	map->s = 0;
	map->w = 0;
	map->e = 0;
	map->height = 0;
	map->heighty = 800;
	map->width = 0;
	map->widthy = 800;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->player_x = 0;
	map->player_y = 0;
	map->floor_r = -1;
	map->floor_g = -1;
	map->floor_b = -1;
	map->ceiling_r = -1;
	map->ceiling_g = -1;
	map->ceiling_b = -1;
	map->map = NULL;
	map->map_fill = NULL;
	map->cub = NULL;
}

void	ft_init_struct_elements(t_elements *elements)
{
	elements->n = false;
	elements->s = false;
	elements->w = false;
	elements->e = false;
	elements->no = false;
	elements->so = false;
	elements->we = false;
	elements->ea = false;
	elements->floor = false;
	elements->ceiling = false;
}
