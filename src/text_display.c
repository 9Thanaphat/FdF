#include "fdf.h"

void	text_display_value_extend(t_vars *vars, void *mlx, void *win, int c)
{
	int		x;
	char	*str;

	x = 208;
	if (vars->env->env_ui)
	{
		if (vars->env->z_factor_select == 0)
			mlx_string_put(mlx, win, 100, x += 16, c, "0.00");
		else if (vars->env->z_factor_select == 1)
			mlx_string_put(mlx, win, 100, x += 16, c, "0.25");
		else if (vars->env->z_factor_select == 2)
			mlx_string_put(mlx, win, 100, x += 16, c, "0.50");
		else if (vars->env->z_factor_select == 3)
			mlx_string_put(mlx, win, 100, x += 16, c, "0.75");
		else if (vars->env->z_factor_select == 4)
			mlx_string_put(mlx, win, 100, x += 16, c, "1.00");
		str = ft_itoa(vars->env->cell_size);
		mlx_string_put(mlx, win, 100, x += 16, c,
			str);
		free(str);
	}
}

void	text_display_value(t_vars *vars, void *mlx, void *win, int c)
{
	int		x;
	char	*str;

	x = 208;
	if (vars->env->env_ui)
	{
		str = ft_itoa(vars->env->offset_x);
		mlx_string_put(mlx, win, 100, x += 16, c, str);
		free(str);
		str = ft_itoa(vars->env->offset_y);
		mlx_string_put(mlx, win, 100, x += 16, c, str);
		free(str);
		str = ft_itoa(vars->env->a_x);
		mlx_string_put(mlx, win, 100, x += 16, c, str);
		free(str);
		str = ft_itoa(vars->env->a_y);
		mlx_string_put(mlx, win, 100, x += 16, c, str);
		free(str);
		str = ft_itoa(vars->env->a_z);
		mlx_string_put(mlx, win, 100, x += 16, c, str);
		free(str);
		text_display_value_extend(vars, mlx, win, c);
	}
}

void	text_display_extend(t_vars *vars, void *mlx, void *win, int c)
{
	int	x;

	x = 192;
	if (vars->env->env_ui)
	{
		mlx_string_put(mlx, win, 10, x += 16, c, "<Values>");
		mlx_string_put(mlx, win, 10, x += 16, c, "x offset :");
		mlx_string_put(mlx, win, 10, x += 16, c, "y offset :");
		mlx_string_put(mlx, win, 10, x += 16, c, "angle x  :");
		mlx_string_put(mlx, win, 10, x += 16, c, "angle y  :");
		mlx_string_put(mlx, win, 10, x += 16, c, "angle z  :");
		mlx_string_put(mlx, win, 10, x += 16, c, "z factor :");
		mlx_string_put(mlx, win, 10, x += 16, c, "cell size :");
	}
	text_display_value(vars, mlx, win, c);
}

void	text_display(t_vars *vars)
{
	void	*mlx;
	void	*win;
	int		c;
	int		x;

	x = 0;
	mlx = vars->mlx_ptr;
	win = vars->mlx_window;
	c = 0xffffff;
	if (vars->env->env_ui)
	{
		mlx_string_put(mlx, win, 10, x += 16, c, "<Control>");
		mlx_string_put(mlx, win, 10, x += 16, c, "Zoom : + or -");
		mlx_string_put(mlx, win, 10, x += 16, c, "Move : < v ^ >");
		mlx_string_put(mlx, win, 10, x += 16, c, "Rotate X-Axis : Q or W");
		mlx_string_put(mlx, win, 10, x += 16, c, "Rotate Y-Axis : A or S");
		mlx_string_put(mlx, win, 10, x += 16, c, "Rotate Z-Axis : Z or X");
		mlx_string_put(mlx, win, 10, x += 16, c, "Z Factor : PgUp or PgDn");
		mlx_string_put(mlx, win, 10, x += 16, c, "Isometric : Ctrl + 1");
		mlx_string_put(mlx, win, 10, x += 16, c, "Top : Ctrl + 2");
		mlx_string_put(mlx, win, 10, x += 16, c, "Side : Ctrl + 3");
		mlx_string_put(mlx, win, 10, x += 16, c, "Toggle Text Display : Del");
	}
	text_display_extend(vars, mlx, win, c);
}
