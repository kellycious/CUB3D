#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_map	t_map;
typedef struct s_mlxy	t_mlxy;
typedef struct s_elements	t_elements;
typedef struct s_map	t_map;

typedef struct s_elements
{
	bool	n;
	bool	s;
	bool	w;
	bool	e;
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	floor;
	bool	ceiling;
	t_map	*map;
}				t_elements;

struct s_mlxy
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	t_map	*map;
};

struct s_map
{
	bool	n;
	bool	s;
	bool	w;
	bool	e;
	void	*mlx;
	void	*win;
	void	*img;
	void	*imgbis;
	char	*addr;
	char	*addrbis;
	int		bpp;
	int		line;
	int		endian;
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		player_x;
	int		player_y;
	float	player_angle;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	char	**map;
	char	**map_fill;
	char	**cub;
	t_mlxy	txt[4];
	t_elements	*elements;
};


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

int	main();

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int		check_arg(int ac, char **av);
int		valid_cub(char **av);
int		open_cub(char *file);
void	ft_parsing(t_map *map, t_elements *elements, char *argv);

/* clean_parsing.c */

void	ft_clean(t_map *map, t_elements *elements);
void	ft_free_map(char **map);
void	ft_clean_rgb(char **rgb, char **rgb_final);
void	ft_clean_rgb_and_exit(char **rgb, char **rgb_final, t_map *map);

/* parse_colors.c */

void	ft_parse_colors(t_map *map);
void	ft_check_and_parse_c(int i, int j, t_map *map);
void	ft_parse_c(int i, t_map *map);
void	ft_parse_f(int i, t_map *map);
char	**ft_get_rgb(int j, int l, char **rgb, t_map *map);

/* utils_colors.c */

void	ft_skip_spaces_rgb(char **rgb, int i, int j, t_map *map);
int		ft_assign_rgb_c(t_map *map, char **rgb_final);
int		ft_assign_rgb_f(t_map *map, char **rgb_final);
void	ft_get_rgb_final(char **rgb_final, char **rgb);
int	ft_above_3_digits(char **rgb, char **rgb_final, int j, t_map *map);

/* utils_colors2.c */

void	ft_only_numbers(char **rgb, char **rgb_final, t_map *map);
int		ft_not_allowed_in_rgb(int i, int j, char **rgb);
void	ft_check_numbers(char **rgb, t_map *map);

/* parse_elements.c */

void	ft_check_elements(t_map *map, t_elements *elements);
void	ft_not_elements(char c, char c2, char c3);
void	ft_assign_elements(char c, char c2, char c3, t_elements *element);
void	ft_parse_textures(t_map *map);
void	ft_get_texture(t_map *map, int i, int j);
int		ft_count_elements(t_map *map, int count);

/* util_elements.c */

int		is_whitespace(char c);
void	ft_elements_error(char c, char c2, char c3, t_map *map);
int		ft_skip_spaces(int i, t_map *map);

/* parse_infile.c */

int		get_cub(t_map *map, char *argv);

/* utils_cub.c */

int		ft_count_line_cub(char *argv, t_map *map);
int		ft_remove_nl(t_map *map);
int		ft_check_cub_ext(char *argv);
void	ft_init_struct_map(t_map *map);
void	ft_init_struct_elements(t_elements *elements);

/* parse_map.c */

int		ft_find_map(t_map *map, t_elements *elements);
void	get_map(t_map *map, t_elements *elements);
int		ft_flood_fill(t_map *map);
int		ft_change_to_player(t_map *map, int i, int j);
int		ft_closed(t_map *map, int i, int j);

/* utils_map.c */

void	ft_copy_map(t_map *map);
void	ft_count_line_map(t_map *map, t_elements *elements);
int		ft_check_players(t_map *map);
void	ft_find_player(t_map *map);
int		ft_check_player(t_map *map, int i, int j);

/* utils_map_fill.c */


void	ft_player_position(t_map *map, int i, int j);
void	ft_change_to(t_map *map, int i, int j);
int		ft_is_player(t_map *map, int i, int j);
int		ft_check_player_around(t_map *map, int i, int j);
int		ft_check_closed(t_map *map);

// RAYCASTING //

void	ray_length(t_rayc *ray);
void	ft_init_ray(t_rayc *ray, t_map *map, float angle);
float	ray_hit_length(t_rayc *ray);
int		ray_caster(t_map *map, t_rayc *ray, float max);
void	move_player(t_map *map, float angle);


#endif