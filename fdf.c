#include "fdf.h"

int main(int argc, char *argv)
{
	t_grid	grid;
	t_cord	**c;
	t_vars	vars;

	read_file("100-6.fdf", &grid);

	printf ("in main | row :%d col:%d\n", grid.row, grid.col);
	
	int start_x = 900;
	int start_y = 100;

	int	gap = 10;
	int	gap_h = 2;

	int	**array;

	array = grid.read_array;

	int	i = 0;
	c = malloc(sizeof(t_cord*) * grid.row);
	while (i < grid.row)
	{
		c[i] = malloc(sizeof(t_cord) * grid.col);
		i++;
	}

	put_to_struct(c, grid, gap, array);

	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, 1920, 1080, "mywindow");

	draw_line_horizontal(grid, c, vars, start_x, start_y);
	draw_line_vertical(grid, c, vars, start_x, start_y);

	mlx_loop(vars.mlx_ptr);
	return (0);
}
