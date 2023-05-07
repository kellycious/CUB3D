#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>

typedef struct s_elements
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	floor;
	bool	ceiling;
}				t_elements;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
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
	t_img	texture[4];
}				t_map;

typedef	struct s_mlxy
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	t_map	map;
}				t_mlxy;

typedef struct s_coor
{
	float	x;
	float	y;

}				t_coor;

typedef struct s_rayc
{
	float	angle;
	t_coor	start;
	t_coor	dir;
	t_coor	length;
	t_coor	unit;
	t_coor	step;
	int		istartx;
	int		istarty;
}				t_rayc;

int	main(int ac, char **av);

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int	check_arg(int ac, char **av);
int	valid_cub(char **av);
int	open_cub(char *file);

#endif