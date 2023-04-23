#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_elements
{
	bool 	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	floor;
	bool	ceiling;
}				t_elements;

typedef struct s_map
{
	int		height;
	int		width;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		player_x;
	int		player_y;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	char	**map;
	char	**map_fill;
	char	**cub;
}				t_map;

int	main(int ac, char **av);

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int	check_arg(int ac, char **av);
int	valid_cub(char **av);
int	open_cub(char *file);

#endif