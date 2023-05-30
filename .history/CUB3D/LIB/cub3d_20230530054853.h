/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:50:55 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/30 05:48:53 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_elements	t_elements;
typedef struct s_map		t_map;

typedef struct s_texture
{
	int		dir;
	double	wallx;
	double	step;
	int		texy;
	int		texx;
	double	pos;

}	t_texture;

typedef struct s_mlx
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
}			t_mlx;

typedef struct s_player
{
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rleft;
	int		rright;
	char	direction;
}			t_player;

typedef struct s_rayc
{
	int			hit;
	int			x;
	double		pwalld;
	double		cam;
	double		rdx;
	double		dirx;
	double		diry;
	double		rdy;
	int			mx;
	int			my;
	double		ddx;
	double		ddy;
	double		planx;
	double		plany;
	int			stepx;
	int			stepy;
	double		px;
	double		py;
	double		sdx;
	double		sdy;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}			t_rayc;

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

struct s_map
{
	bool		n;
	bool		s;
	bool		w;
	bool		e;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			player_x;
	int			player_y;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
	char		**map;
	char		**map_fill;
	char		**cub;
	int			heighty;
	int			widthy;
	int			height;
	size_t		width;
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			*addrbis;
	void		*imgbis;
	int			bpp;
	int			line;
	int			endian;
	t_texture	tex;
	t_mlx		txt[4];
	t_elements	*elements;
	t_player	*player;
	t_rayc		ray;
};

int				main(int ac, char **av);

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int				valid_cub(char **av);
int				open_cub(char *file);
void			ft_parsing(t_map *map, t_elements *elements,
					int ac, char *argv);

/* clean_parsing.c */

void			ft_clean(t_map *map, t_elements *elements);
void			ft_free_map(char **map);
void			ft_clean_rgb(char **rgb, char **rgb_final);
void			ft_clean_rgb_and_exit(char **rgb, char **rgb_final, t_map *map);

/* clean_parsing2.c */

void			ft_not_closed_and_clean(t_map *map);
void			ft_map_not_well_formated(t_map *map);

/* parse_colors.c */

void			ft_parse_colors(t_map *map);
void			ft_check_and_parse_c(int i, int j, t_map *map);
void			ft_parse_c(int i, t_map *map);
void			ft_parse_f(int i, t_map *map);
char			**ft_get_rgb(int j, int l, char **rgb, t_map *map);

/* utils_colors.c */

void			ft_skip_spaces_rgb(char **rgb, int i, int j, t_map *map);
int				ft_assign_rgb_c(t_map *map, char **rgb_final);
int				ft_assign_rgb_f(t_map *map, char **rgb_final);
void			ft_get_rgb_final(char **rgb_final, char **rgb);
int				ft_above_3_digits(char **rgb, char **rgb_final,
					int j, t_map *map);

/* utils_colors2.c */

int	ft_check_if_only_one_num(char **rgb);
int	ft_skip_zero(char **rgb, int i, int j);
void			ft_check_numbers(char **rgb, t_map *map);
int				ft_count_numbers(char **rgb, int i, int count);

/* utils_colors3.c */

void			ft_only_numbers(char **rgb, t_map *map);
int				ft_not_allowed_in_rgb(int i, int j, char **rgb);

/* parse_elements.c */

void			ft_check_elements(t_map *map);
void			ft_not_elements(char c, char c2, char c3);
void			ft_assign_elements(char c, char c2, char c3, t_map *map);
void			ft_parse_textures(t_map *map);
void			ft_get_texture(t_map *map, int i, int j);

/* util_elements.c */

int				is_whitespace(char c);
void			ft_elements_error(char c, char c2, char c3, t_map *map);
int				ft_skip_spaces(int i, t_map *map);
int				ft_check_other_char(t_map *map);
int				ft_count_elements(t_map *map, int count);

/* parse_infile.c */

int				get_cub(t_map *map, int ac, char *argv);
void			is_dir(const char *path, t_map *game);

/* utils_cub.c */

int				ft_count_line_cub(char *argv, t_map *map);
int				ft_remove_nl(t_map *map);
int				ft_check_cub_ext(char *argv);
void			ft_init_struct_map(t_map *map);
void			ft_init_struct_elements(t_elements *elements);

/* parse_map.c */

int				ft_find_map(t_map *map);
void			get_map(t_map *map);
int				ft_flood_fill(t_map *map, bool player);
int				ft_change_to_player(t_map *map, int i, int j);
int				ft_closed(t_map *map, int i, int j);

/* utils_map.c */

void			ft_copy_map(t_map *map);
void			ft_count_line_map(t_map *map);
int				ft_check_players(t_map *map);
void			ft_find_player(t_map *map);
int				ft_check_player(t_map *map, int i, int j);

/* utils_map_fill.c */

void			ft_player_position(t_map *map, int i, int j);
void			ft_change_to(t_map *map, int i, int j);
int				ft_is_player(t_map *map, int i, int j);
int				ft_check_player_around(t_map *map, int i, int j);
int				ft_check_closed(t_map *map);

// RAYCASTING //

int				render_map(t_map *game);
void			ft_cleaner(t_map *game, char *error);
int				raycaster(t_map *game);
void			init_ray2(t_map *game);
void			player_init(t_map *game, char direction);
int				key_press(int keycode, t_map *game);
int				key_release(int keycode, t_map *game);
int				exit_game(t_map *game);
void			forward(t_map *game);
void			backward(t_map *game);
void			left(t_map *game);
void			right(t_map *game);
void			r_left(t_map *game);
void			r_right(t_map *game);
char			p_position(t_map *cub);
void			init_texture(t_map *game);
void			wallcheck(t_map *game);
void			wall_coor(t_map *game);
void			swapy(t_map *game);
void			draw_texture(t_map *game);
void			gtext_wall(t_map *game, int x, int y);
void			texture_img(t_map *game);
int				move_player(t_map *game);

#endif