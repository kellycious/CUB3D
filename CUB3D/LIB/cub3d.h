#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

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
	bool	n;
	bool	s;
	bool	w;
	bool	e;
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

int	main();

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int	check_arg(int ac, char **av);
int	valid_cub(char **av);
int	open_cub(char *file);
void	ft_parsing(t_map *map, t_elements *elements, char *argv);

/* clean_parsing.c */

void	ft_clean_colors(char **rgb, char **rgb_final);
void	ft_clean(t_map *map);
void	ft_free_map(char **map);

/* parse_colors.c */

void	ft_parse_colors(t_map *map);
void	ft_check_and_parse_c(int i, int j, t_map *map);
void	ft_parse_c(int i, t_map *map);
void	ft_parse_f(int i, t_map *map);
char	**ft_get_rgb(int i, int j, int l, char **rgb);

/* utils_colors.c */

void	ft_skip_spaces_rgb(char **rgb, int i, int j);
void	ft_assign_rgb_c(t_map *map, char **rgb_final);
void	ft_assign_rgb_f(t_map *map, char **rgb_final);
void	ft_get_rgb_final(char **rgb_final, char **rgb);

/* parse_elements.c */

void	ft_check_elements(t_map *map, t_elements *elements);
void	ft_not_elements(char c, char c2, char c3);
void	ft_assign_elements(char c, char c2, char c3, t_elements *element);
void	ft_parse_textures(t_map *map);
void	ft_get_texture(t_map *map, int i, int j);
int		ft_count_elements(t_map *map, int count);

/* util_elements.c */

int		is_whitespace(char c);
void	ft_elements_error(char c, char c2, char c3);
int		ft_skip_spaces(int i, t_map *map);

/* parse_infile.c */

int		get_cub(t_map *map, char *argv);

/* utils_cub.c */

int		ft_count_line_cub(char *argv, t_map *map);
int		ft_remove_nl(t_map *map);
int		ft_check_cub_ext(char *argv);
void	ft_init_struct_map(t_map *map);

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
int		ft_check_closed(t_map *map);
int		ft_check_player_around(t_map *map, int i, int j);
int		ft_is_player(t_map *map, int i, int j);


#endif