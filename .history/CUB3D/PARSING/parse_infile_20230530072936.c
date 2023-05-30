/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:43:11 by fwong             #+#    #+#             */
/*   Updated: 2023/05/30 07:29:36 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static int	check_arg(int ac)
{
	if (ac == 2)
		return (1);
	return (ft_putstr_fd("Error\ninvalid nb of arg\n", 2), 0);
}

void	is_dir(const char *path, t_map *game)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
			return (ft_putstr_fd("Error\n.cub file is a dir\n", 2),
				ft_clean(game, game->elements), exit(0));
	}
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
		fd = open(argv, O_RDWR);
		if (fd <= -1)
			return (ft_putstr_fd("Error\n.cub file does not exist\n",
					2), close(fd), 0);
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

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char));
	if (!copy)
		return (0);
	j = 0;
	while (j < i)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
