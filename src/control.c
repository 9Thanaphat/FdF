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

void	move_offset(int key, t_vars *vars)
{
	if (key == ARROW_UP)
		vars->grid_ptr->start_y -= 5;
	else if (key == ARROW_DOWN)
		vars->grid_ptr->start_y += 5;
	else if (key == ARROW_LEFT)
		vars->grid_ptr->start_x -= 5;
	else if (key == ARROW_RIGHT)
		vars->grid_ptr->start_x += 5;
}

void	rotation(int key, t_vars *vars)
{
	vars->grid_ptr->angle_x = 0;
	vars->grid_ptr->angle_y = 0;
	vars->grid_ptr->angle_z = 0;
	if (key == KEY_Q)
		vars->grid_ptr->angle_x += 1;
	if (key == KEY_W)
		vars->grid_ptr->angle_x -= 1;
	if (key == KEY_A)
		vars->grid_ptr->angle_y += 1;
	if (key == KEY_S)
		vars->grid_ptr->angle_y -= 1;
	if (key == KEY_Z)
		vars->grid_ptr->angle_z += 1;
	if (key == KEY_X)
		vars->grid_ptr->angle_z -= 1;
	draw_edge(vars);
}

int	key_press(int key, t_vars *vars)
{
	printf("Key pressed: %d\n", key);
	if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT || key == ARROW_RIGHT)
		move_offset(key, vars);
	if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X)
		rotation(key, vars);
	my_clear_img(vars->img_ptr, WIDTH, HEIGHT);
	draw_line_horizontal(vars->grid_ptr, vars, vars->img_ptr);
	draw_line_vertical(vars->grid_ptr, vars, vars->img_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window, vars->img_ptr->img, 0, 0);
	return (0);
}
