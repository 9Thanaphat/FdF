#include "fdf.h"

int close_window(t_vars *vars) {
	printf("Close Window\n");
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->grid_ptr->array);
	exit(0);
	return (0);
}

int key_press(int keycode, t_vars *vars)
{
	//printf("Key pressed: %d\n", keycode);
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
		vars->grid_ptr->height += 1;
	else if (keycode == 65366)
		vars->grid_ptr->height -= 1;
	else if (keycode == 61)
		vars->grid_ptr->tile_size += 1;
	else if (keycode == 45)
		vars->grid_ptr->tile_size -= 1;
	my_clear_img(vars->img_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	draw_line_horizontal(vars->grid_ptr, vars, vars->img_ptr);
	draw_line_vertical(vars->grid_ptr, vars, vars->img_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window, vars->img_ptr->img, 0, 0);
	return (0);
}

int main(int argc, char *argv)
{
	t_grid	grid;
	t_vars	vars;
	t_data	img;

	read_file("maps/test_maps/mars.fdf", &grid);
	printf ("in main | row :%d col:%d\n", grid.row, grid.col);
	printf("min : %d max : %d\n", grid.min, grid.max);

	grid.start_x = 0;
	grid.start_y = 0;
	grid.tile_size = 20;
	grid.height = 8;

	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mywindow");
	vars.grid_ptr = &grid;

	img.img = mlx_new_image(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img_ptr = &img;
	draw_line_horizontal(&grid, &vars, &img);
	draw_line_vertical(&grid, &vars, &img);

	mlx_hook(vars.mlx_window, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	mlx_loop(vars.mlx_ptr);
	
	return (0);
}
