#include "fdf.h"

int toIso_x(t_grid *grid, int i, int j)
{
	int	x;
	int	y;

	x = (i * grid->tile_size) + grid->start_x;
	y = (j * grid->tile_size) + grid->start_y;
	return (x - y + (0.1 * grid->array[j * grid->col + i]));
}

int toIso_y(t_grid *grid, int	i, int j)
{
	int	x;
	int	y;
	int	z;
	
	x = (i  * grid->tile_size) + grid->start_x;
	y = (j * grid->tile_size) + grid->start_y;
	z =  grid->array[j * grid->col + i] * (grid->height);

	return (((x + y) / 2) - z);
}
