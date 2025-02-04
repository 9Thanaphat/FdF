#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data->addr || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

void	draw_line_draw(t_points *points, t_vars *vars, int e2, int total_steps)
{
	int	step;

	step = 0;
	while (1)
	{
		my_mlx_pixel_put(vars->img_ptr, points->iso_x1, points->iso_y1,
		ft_gradient(0xFFFFFF, 0x7d2819, 256,
		ft_map(points->z, vars->grid_ptr->min, vars->grid_ptr->max, 0, 255)));
		if (points->iso_x1 == points->iso_x2 && points->iso_y1 == points->iso_y2) // หากถึงจุดสิ้นสุดให้หยุด
			break;
		e2 = points->err * 2; // อัปเดตค่าผิดพลาดและพิกัด
		if (e2 > -points->dy)
		{
			points->err -= points->dy;
			points->iso_x1 += points->sx;
		}
		if (e2 < points->dx)
		{
			points->err += points->dx;
			points->iso_y1 += points->sy;
		}
		points->z = points->z1 + ((points->z2 - points->z1) * step) / total_steps; // อัปเดตค่า z ในแต่ละขั้น โดยการไล่จาก z1 ไป z2
		step++;
	}
}

void	draw_line(t_points *points, t_vars *vars)
{
	int	total_steps;
	int	e2;

	if (points->dx > points->dy)
		total_steps = points->dx;
	else
		total_steps = points->dy;
	points->dx = abs(points->iso_x2 - points->iso_x1);
	points->dy = abs(points->iso_y2 - points->iso_y1);
	points->dz = abs(points->z2 - points->z1);
	points->err = points->dx - points->dy;
	points->z = points->z1;
	if (points->iso_x1 < points->iso_x2)
		points->sx = 1;
	else
		points->sx = -1;
	if (points->iso_y1 < points->iso_y2)
		points->sy = 1;
	else
		points->sy = -1;
	draw_line_draw(points, vars, e2, total_steps);
}

void	draw_line_horizontal(t_grid *grid, t_vars *vars, t_data *img)
{
	t_points	points;
	int			i;
	int			j;

	j = 0;
	while (j < grid->row)
	{
		i = 0;
		while (i < grid->col)
		{
			if (i < (grid->col - 1))
			{
				points.iso_x1 = toIso_x(grid, i, j);
				points.iso_y1 = toIso_y(grid, i, j);
				points.iso_x2 = toIso_x(grid, i + 1, j);
				points.iso_y2 = toIso_y(grid, i + 1, j);
				points.z1 = grid->array[j * grid->col + i]->height;
				points.z2 = grid->array[j* grid->col + (i + 1)]->height;
				draw_line(&points, vars);
			}
			i++;
		}
		j++;
	}
}

void	draw_line_vertical(t_grid *grid, t_vars *vars, t_data *img)
{
	t_points	points;
	int	i;
	int	j;

	i = 0;
	while (i < grid->col)
	{
		j = 0;
		while (j < grid->row)
		{
			if (j < (grid->row - 1))
			{
				points.iso_x1 = toIso_x(grid, i, j);
				points.iso_y1 = toIso_y(grid, i, j);
				points.iso_x2 = toIso_x(grid, i, j + 1);
				points.iso_y2 = toIso_y(grid, i, j + 1);
				points.z1 = grid->array[j * grid->col + i]->height;
				points.z2 = grid->array[(j + 1)* grid->col + i]->height;
				draw_line(&points, vars);
			}
			j++;
		}
		i++;
	}
}
