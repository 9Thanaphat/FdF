#include "fdf.h"

int key_press(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65362)
	{
		vars->grid_ptr->start_x -= 5;
		vars->grid_ptr->start_y -= 5;
	}
	else if (keycode == 65364)
	{
		vars->grid_ptr->start_x += 5;
		vars->grid_ptr->start_y += 5;
	}
	else if (keycode == 65361)
	{
		vars->grid_ptr->start_x -= 5;
		vars->grid_ptr->start_y += 5;
	}
	else if (keycode == 65363)
	{
		vars->grid_ptr->start_x += 5;
		vars->grid_ptr->start_y -= 5;
	}
	else if (keycode == 65365)
		vars->grid_ptr->tile_size += 1;
	else if (keycode == 65366)
		vars->grid_ptr->tile_size -= 1;
	mlx_clear_window(vars->mlx_ptr, vars->mlx_window);
	draw_line_horizontal(vars->grid_ptr, vars);
	draw_line_vertical(vars->grid_ptr, vars);
	return (0);
}

int main(int argc, char *argv)
{
	t_grid	grid;
	t_vars	vars;

	read_file("pylone.fdf", &grid);

	printf ("in main | row :%d col:%d\n", grid.row, grid.col);

	grid.start_x = 0;
	grid.start_y = 0;
	grid.tile_size = 10;

	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, 1920, 1080, "mywindow");
	vars.grid_ptr = &grid;

	draw_line_horizontal(&grid, &vars);
	draw_line_vertical(&grid, &vars);

	mlx_hook(vars.mlx_window, 2, 1L<<0, key_press, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
