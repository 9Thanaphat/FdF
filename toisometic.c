#include "fdf.h"

float toIso_x(t_grid *grid, int i, int j)
{
	float	x;
	float	y;

	x = (i * grid->tile_size) + grid->start_x;
	y = (j * grid->tile_size) + grid->start_y;
	return (x - y);
}

float toIso_y(t_grid *grid, int	i, int j)
{
	float	x;
	float	y;
	float	z;
	
	x = (i  * grid->tile_size) + grid->start_x;
	y = (j * grid->tile_size) + grid->start_y;
	z =  grid->array[j * grid->col + i] * (grid->height);
	return (((x + y) / 2) - z);
}
