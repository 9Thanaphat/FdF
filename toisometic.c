#include "fdf.h"

float toIso_x(t_grid grid, int i, int j)
{
	float	x;
	float	y;

	x = (i * grid.tile_size) + grid.start_x;
	y = (j * grid.tile_size) + grid.start_y;
	printf("to iso x : %.2f\n", x - y);
	return (x - y);
}

float toIso_y(t_grid grid, int	i, int j)
{
	float	x;
	float	y;
	float	z;

	x = (i  * grid.tile_size) + grid.start_x;
	y = (j *grid.tile_size) + grid.start_y;
	z =  grid.read_array[j][i] * grid.tile_size;
	printf("to iso y : %.2f\n", ((x + y) / 2) - z);
	return (((x + y) / 2) - z);
}
