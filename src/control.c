#include "fdf.h"

void	set_z_factor(t_vars *vars)
{
	if (vars->env->z_factor_select == 0)
		vars->env->z_factor = 0.00;
	else if (vars->env->z_factor_select == 1)
		vars->env->z_factor = 0.25;
	else if (vars->env->z_factor_select == 2)
		vars->env->z_factor = 0.50;
	else if (vars->env->z_factor_select == 3)
		vars->env->z_factor = 0.75;
	else if (vars->env->z_factor_select == 4)
		vars->env->z_factor = 1.00;
}

int	close_window(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->env->col * vars->env->row)
	{
		free(vars->env->array[i]);
		i++;
	}
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->env->array);
	free(vars->mlx_ptr);
	exit(0);
	return (0);
}

void	move_offset(int key, t_vars *vars)
{
	if (key == ARROW_UP)
		vars->env->offset_y -= 5;
	else if (key == ARROW_DOWN)
		vars->env->offset_y+= 5;
	else if (key == ARROW_LEFT)
		vars->env->offset_x -= 5;
	else if (key == ARROW_RIGHT)
		vars->env->offset_x += 5;
}

void	rotation(int key, t_vars *vars)
{
	if (key == KEY_Q)
		vars->env->a_x += 1;
	if (key == KEY_W)
		vars->env->a_x -= 1;
	if (key == KEY_A)
		vars->env->a_y += 1;
	if (key == KEY_S)
		vars->env->a_y -= 1;
	if (key == KEY_Z)
		vars->env->a_z += 1;
	if (key == KEY_X)
		vars->env->a_z -= 1;
	if (key == KEY_PLUS)
		vars->env->cell_size++;
	if (key == KEY_MINUS && vars->env->cell_size > 1)
		vars->env->cell_size--;
}

void	change_projection(int key, t_vars *vars)
{
	if (key == KEY_1)
	{
		vars->env->a_x = 0;
		vars->env->a_y = 0;
		vars->env->a_z = 0;
	}
	else if (key == KEY_2)
	{
		vars->env->a_x = 180;
		vars->env->a_y = 270;
		vars->env->a_z = 270;
	}
	else if (key == KEY_3)
	{
		vars->env->a_x = 90;
		vars->env->a_y = 0;
		vars->env->a_z = 0;
	}
	else if (key == KEY_4)
	{
		vars->env->a_x = 45;
		vars->env->a_y = -30;
		vars->env->a_z = 30;
	}
}

int	key_press(int key, t_vars *vars)
{
	if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT || key == ARROW_RIGHT)
		move_offset(key, vars);
	if (key == KEY_Q || key == KEY_W || key == KEY_A|| key == KEY_S
		|| key == KEY_Z || key == KEY_X || key == KEY_PLUS
		|| key == KEY_MINUS)
		rotation(key, vars);
	if (key == KEY_PAGE_DOWN && vars->env->z_factor_select > 0)
		vars->env->z_factor_select--;
	if (key == KEY_PAGE_UP && vars->env->z_factor_select < 4)
		vars->env->z_factor_select++;
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		change_projection(key, vars);
	if (key == KEY_DEL)
		vars->env->env_ui = 0;
	if (key == ESC)
		close_window(vars);
	set_z_factor(vars);
	my_clear_img(vars->img_ptr, WIDTH, HEIGHT);
	draw_line_horizontal(vars->env, vars, vars->img_ptr);
	draw_line_vertical(vars->env, vars, vars->img_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window, vars->img_ptr->img, 0, 0);
	text_display(vars);
	return (0);
}
