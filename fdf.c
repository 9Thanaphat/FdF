#include "fdf.h"

void text_display(t_vars *vars)
{
	int	x;
	int y;
		
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < 200)
		{
			my_mlx_pixel_put(vars->img_ptr, x, y, 0x004389FA);
			x++;
		}
		y++;
	}
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 25, 25, 0xFFFFFF, "Tile Size :");
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 125, 25, 0xFFFFFF, ft_itoa(vars->grid_ptr->tile_size));
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 25, 50, 0xFFFFFF, "Tile Height :");
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 125, 50, 0xFFFFFF, ft_itoa(vars->grid_ptr->height));
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
	text_display(vars);
	return (0);
}

int main(int argc, char *argv)
{
	t_grid	grid;
	t_vars	vars;
	t_data	img;

	read_file("maps/test_maps/t2.fdf", &grid);
	printf ("in main | row :%d col:%d\n", grid.row, grid.col);
	printf("min : %d max : %d\n", grid.min, grid.max);

	grid.start_x = 0;
	grid.start_y = 0;
	grid.tile_size = 10;
	grid.height = 5;

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
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	text_display(&vars);
	mlx_loop(vars.mlx_ptr);
	
	return (0);
}
