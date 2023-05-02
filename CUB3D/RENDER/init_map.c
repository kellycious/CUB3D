#include "../LIB/cub3d.h"

int	init_mlx(t_mlxy *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("Error: mlx init\n", 2), 1);
	return (init_img(map));
}

int	init_img(t_mlxy *mlxy)
{
	mlxy->img = mlx_new_image(mlxy->mlx, 800, 600);
	if (!mlxy->img)
		return (ft_putstr_fd("Error: mlx image\n", 2), 0);
	mlxy->addr = mlx_get_data_addr(mlxy->img, &mlxy->bpp, &mlxy->line, &mlxy->endian);
	if (!mlxy->addr)
		return (ft_putstr_fd("Error: mlx addr\n", 2), 0);
	ft_memset(mlxy->addr, 0, mlxy->map.height * mlxy->map.width * (mlxy->bpp / 8));
	return (1);
}

int	init_window(t_mlxy *mlxy)
{
	mlxy->win = mlx_new_window(mlxy->mlx, 800, 600, "Cubi3D");
	if (!mlxy->win)
		return(ft_putstr_fd("Error: mlx window\n",2), 0);
	mlx_loop_hook(mlxy->mlx, XXXXX, mlxy);
	mlx_hook(mlxy->win, DestroyNotify, NoEventMask, destroyer, mlxy);
	mlx_hook(mlxy->win, KeyPress, KeyPressMask, XXXX, mlxy);
	mlx_hook(mlxy->win, KeyRelease, KeyReleaseMask, XXXX, mlxy);
	return (0);
}

int	destroyer(t_mlxy *mlxy)
{
	return(mlx_loop_end(mlxy->mlx));
}