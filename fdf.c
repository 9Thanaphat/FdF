#include "fdf.h"

int main(int argc, char *argv)
{
	t_grid	grid;
	t_vars	vars;

	read_file("pylone.fdf", &grid);

	printf ("in main | row :%d col:%d\n", grid.row, grid.col);

	grid.start_x = 800;
	grid.start_y = 300;
	grid.tile_size = 10;

	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, 1920, 1080, "mywindow");

	draw_line_horizontal(grid, vars);
	draw_line_vertical(grid, vars);

	mlx_loop(vars.mlx_ptr);
	return (0);
}
