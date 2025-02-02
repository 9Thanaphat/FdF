#include "fdf.h"

int close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->grid_ptr->array);
	free(vars->mlx_ptr);
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
	my_clear_img(vars->img_ptr, WIDTH, HEIGHT);
	draw_line_horizontal(vars->grid_ptr, vars, vars->img_ptr);
	draw_line_vertical(vars->grid_ptr, vars, vars->img_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window, vars->img_ptr->img, 0, 0);
	return (0);
}
