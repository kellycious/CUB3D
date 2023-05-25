/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:47:08 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/26 00:40:44 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/cub3d.h"

static void	init_txt(t_map *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(&game->txt[i], sizeof(t_mlx));
		game->txt[i].img = NULL;
		game->txt[i].addr = NULL;
		game->txt[i].width = 0;
		game->txt[i].height = 0;
		game->txt[i].bpp = 0;
		game->txt[i].line = 0;
		game->txt[i].endian = 0;
		i++;
	}
}

void	texture_pix(t_map *game)
{
	game->txt[NORTH].addr = (int *)mlx_get_data_addr(game->txt[NORTH].img,
			&game->txt[NORTH].bpp, &game->txt[NORTH].line,
			&game->txt[NORTH].endian);
	if (!game->txt[NORTH].addr)
		return (ft_cleaner(game, "Error: mlx get data addr\n"));
	game->txt[SOUTH].addr = (int *)mlx_get_data_addr(game->txt[SOUTH].img,
			&game->txt[SOUTH].bpp, &game->txt[SOUTH].line,
			&game->txt[SOUTH].endian);
	if (!game->txt[SOUTH].addr)
		return (ft_cleaner(game, "Error: mlx get data addr\n"));
	game->txt[WEST].addr = (int *)mlx_get_data_addr(game->txt[WEST].img,
			&game->txt[WEST].bpp, &game->txt[WEST].line,
			&game->txt[WEST].endian);
	if (!game->txt[WEST].addr)
		return (ft_cleaner(game, "Error: mlx get data addr\n"));
	game->txt[EAST].addr = (int *)mlx_get_data_addr(game->txt[EAST].img,
			&game->txt[EAST].bpp, &game->txt[EAST].line,
			&game->txt[EAST].endian);
	if (!game->txt[EAST].addr)
		return (ft_cleaner(game, "Error: mlx get data addr\n"));
}

void	texture_img(t_map *game)
{
	init_txt(game);
	game->txt[NORTH].img = mlx_xpm_file_to_image(game->mlx, game->no,
			&game->txt[NORTH].width, &game->txt[NORTH].height);
	if (!game->txt[NORTH].img)
		return (ft_cleaner(game, "Error: mlx xpm file to image\n"));
	game->txt[SOUTH].img = mlx_xpm_file_to_image(game->mlx, game->so,
			&game->txt[SOUTH].width, &game->txt[SOUTH].height);
	if (!game->txt[SOUTH].img)
		return (ft_cleaner(game, "Error: mlx xpm file to image\n"));
	game->txt[WEST].img = mlx_xpm_file_to_image(game->mlx, game->we,
			&game->txt[WEST].width, &game->txt[WEST].height);
	if (!game->txt[WEST].img)
		return (ft_cleaner(game, "Error: mlx xpm file to image\n"));
	game->txt[EAST].img = mlx_xpm_file_to_image(game->mlx, game->ea,
			&game->txt[EAST].width, &game->txt[EAST].height);
	if (!game->txt[EAST].img)
		return (ft_cleaner(game, "Error: mlx xpm file to image\n"));
	texture_pix(game);
}

static int	rgbtohex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_texture(t_map *game)
{
	int	j;
	int	i;

	j = -1;
	game->ray.drawend = 800 - game->ray.drawstart;
	i = game->ray.drawend;
	while (++j < game->ray.drawstart)
		game->addr[j * game->line / 4
			+ game->ray.x] = rgbtohex(game->ceiling_r,
				game->ceiling_g, game->ceiling_b);
	if (j <= game->ray.drawend)
		gtext_wall(game, game->ray.x, j);
	j = i;
	while (++j < 800)
		game->addr[j * game->line / 4
			+ game->ray.x] = rgbtohex(game->floor_r,
				game->floor_g, game->floor_b);
}
