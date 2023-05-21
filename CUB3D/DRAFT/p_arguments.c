#include "../LIB/cub3d.h"

int	check_arg(int ac, char **av)
{
	if (ac == 2)
		return (valid_);
	return (ft_putstr_fd("ERROR: invalid nb of arg\n", 2), 0);
}

int	valid_cub(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	while (av[1][i] != '.')
	{
		i--;
		if (i == 0)
			return (ft_putstr_fd("ERROR: invalid map file\n", 2), 0);
	}
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u' && av[1][i + 3] == 'b')
		return (open_cub(av[1]));
	else
		return (ft_putstr_fd("ERROR: invalid map file\n", 2), 0);
}

int	open_cub(char *file)
{
	int	fd;

	fd = open(file, __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), \
			ft_putstr_fd("ERROR: map file is a directory\n", 2), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (close(fd), \
			ft_putstr_fd("ERROR: map file does not exist\n", 2), 0);
	// ajouter fonction copy_map
	close (fd);
	return (0);
}
