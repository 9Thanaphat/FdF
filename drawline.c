#include "fdf.h"

void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1) {
		mlx_pixel_put(mlx, win, x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		int e2 = err * 2;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void	draw_line_horizontal(t_grid grid, t_cord **c, t_vars vars, int start_x, int start_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < grid.row)
	{
		while (i < grid.col)
		{
			if (i < (grid.col - 1))
				draw_line(
				toIso_x(&c[j][i]) + start_x,
				toIso_y(&c[j][i]) + start_y,
				toIso_x(&c[j][i + 1]) + start_x,
				toIso_y(&c[j][i + 1]) + start_y,
				vars.mlx_ptr, vars.mlx_window, 0xFFFFFF);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_line_vertical(t_grid grid, t_cord **c, t_vars vars, int start_x, int start_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < grid.col)
	{
		while (j < grid.row)
		{
		if (j < (grid.row - 1))
				draw_line(
				toIso_x(&c[j][i]) + start_x,
				toIso_y(&c[j][i]) + start_y,
				toIso_x(&c[j + 1][i]) + start_x,
				toIso_y(&c[j + 1][i]) + start_y,
				vars.mlx_ptr, vars.mlx_window, 0x32A852);
			j++;
		}
		j = 0;
		i++;
	}
}
