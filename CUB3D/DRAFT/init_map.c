#include "../LIB/cub3d.h"

int	init_mlx(t_mlxy *texture)
{
	texture->mlx = mlx_init();
	if (!texture->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (init_img(texture));
}

int	init_img(t_mlxy *texture)
{
	texture->img = mlx_new_image(mlxy->mlx, 800, 600);
	if (!texture->img)
		return (ft_putstr_fd("Error: mlx image\n", 2), 0);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
		&texture->line, &texture->endian);
	if (!texture->addr)
		return (ft_putstr_fd("Error: mlx addr\n", 2), 0);
	ft_memset(texture->addr, 0,
		(texture->map.height * texture->map.width * (mlxy->bpp / 8)));
	return (1);
}

int	init_window(t_mlxy *mlxy)
{
	mlxy->win = mlx_new_window(mlxy->mlx, 800, 600, "Cubi3D");
	if (!mlxy->win)
		return (ft_putstr_fd("Error: mlx window\n", 2), 0);
	mlx_loop_hook(mlxy->mlx, XXXXX, mlxy);
	return (0);
}

void	render_map(t_map *map, t_mlxy *mlxy)
{
	t_rayc *rayc;
	float	max_distance;
	int		x;

	x = 0;
	while (x < 800)
	{
		ft_init_ray(rayc, mlxy, x);
		max_distance = ray_caster(rayc, map, x);
		render_3d_walls(rayc, mlxy, max_distance, x);
		x++;
	}
}