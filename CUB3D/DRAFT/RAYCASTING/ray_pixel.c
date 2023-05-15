#include "../LIB/cub3d.h"


/* ---------------

color = pixel RGB value;
0 = not hit, black | hit, white
shading depending on distance, 75% > 50% > 25%)
Shift color to 2 bits each time to darken the color 
by reducing intensity
setting alpha to make it transparent

------------------ */

int	raycast_colorpix(t_map *map, t_rayc *ray)
{
	int	color;

	if (ray->distance < 0.0f)
		color = 0;
	else
		color = 0xFFFFFF;
	if (ray->distance > 1.0f)
		color = (color & 0xFCFCFC) >> 2;
	if (ray->distance > 2.0f)
		color = (color & 0xF8F8F8) >> 2;
	if (ray->distance > 3.0f)
		color = (color & 0xF0F0F0) >> 2;
	// apply wall texture
	return (color);
}

/* ---------------

retrieve the texture color
calculate the memory address of the texture's pixel matching
current pixel rendered on screen

------------------ */

int	texture_colorpix(t_map *map, int col, float texy)
{
	int		color;
	char	*ad;

	ad = 
}