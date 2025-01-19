#include "fdf.h"

int close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->grid_ptr->array);
	exit(0);
	return (0);
}