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

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_elements
{
	bool	no;
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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		player_x;
	int		player_y;
	int		player_angle;
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
	t_coor	gline;
	t_coor	step;
	int		istartx;
	int		istarty;
	int		hit_dir;
	t_coor	result;
	float	distance;
}				t_rayc;

int	main(int ac, char **av);

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int	check_arg(int ac, char **av);
int	valid_cub(char **av);
int	open_cub(char *file);

// RAYCASTING //

void	ray_length(t_rayc *ray);
void	ft_init_ray(t_rayc *ray, t_map *map, float angle);
float	ray_hit_length(t_rayc *ray);
int		ray_caster(t_map *map, t_rayc *ray, float max);
void	move_player(t_map *map, float angle);


#endif