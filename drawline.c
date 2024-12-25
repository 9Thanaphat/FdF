#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (!data->addr || x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT){
		return;
	}
		
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_clear_img(t_data *data, int w, int h)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(data, i, j, 0x00000000);
			i++;
		}
		j++;
	}
}

void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color, t_data *img)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1) {
		my_mlx_pixel_put(img, x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		int e2 = err * 2;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void	draw_line_horizontal(t_grid *grid, t_vars *vars, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < grid->row)
	{
		i = 0;
		while (i < grid->col)
		{
			if (i < (grid->col - 1))
				draw_line(
				toIso_x(grid, i, j),
				toIso_y(grid, i, j),
				toIso_x(grid, i + 1, j),
				toIso_y(grid, i + 1, j),
				vars->mlx_ptr, vars->mlx_window, 0x00FFFFFF, img);
			i++;
		}
		j++;
	}
}

void	draw_line_vertical(t_grid *grid, t_vars *vars, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->col)
	{
		j = 0;
		while (j < grid->col)
		{
			if (j < (grid->row - 1))
				draw_line(
				toIso_x(grid, i, j),
				toIso_y(grid, i, j),
				toIso_x(grid, i, j + 1),
				toIso_y(grid, i, j + 1),
				vars->mlx_ptr, vars->mlx_window, 0x00FFFFFF, img);
			j++;
		}
		i++;
	}
}