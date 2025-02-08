#include "fdf.h"
#include <math.h>

void rotate(t_list *node, t_grid *grid, float *sx, float *sy)
{
    float x, y, z;

    // ใช้ค่าต้นฉบับของจุด
    x = node->x;
    y = node->y;
    z = node->z;

    float new_y = y * cos(grid->angle_x * PI / 180) - z * sin(grid->angle_x * PI / 180);
    float new_z = y * sin(grid->angle_x * PI / 180) + z * cos(grid->angle_x * PI / 180);
    y = new_y;
    z = new_z;

    float new_x = x * cos(grid->angle_y * PI / 180) + z * sin(grid->angle_y * PI / 180);
    new_z = -x * sin(grid->angle_y * PI / 180) + z * cos(grid->angle_y * PI / 180);
    x = new_x;
    z = new_z;

    new_x = x * cos(grid->angle_z * PI / 180) - y * sin(grid->angle_z * PI / 180) ;
    new_y = x * sin(grid->angle_z * PI / 180)  + y * cos(grid->angle_z * PI / 180) ;
    x = new_x;
    y = new_y;

    *sx = round((x * 10) + grid->start_x);
    *sy = round((y * 10) + grid->start_y);

}

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
	int	color_1;
	int	color_2;
	int percent;

	color_1 = 0xFF0000;
	color_2 = 0xFF00ff;
	if (vars->grid_ptr->array[points->index_1]->color != 0)
		color_1 = vars->grid_ptr->array[points->index_1]->color;
	if (vars->grid_ptr->array[points->index_2]->color != 0)
		color_2 = vars->grid_ptr->array[points->index_2]->color;
	step = 0;
	while (1)
	{
		if (total_steps == 0) {
			total_steps = 1;
		}
		my_mlx_pixel_put(vars->img_ptr, points->iso_x1, points->iso_y1, 0x00FF00);
		if (points->iso_x1 == points->iso_x2 && points->iso_y1 == points->iso_y2) // หากถึงจุดสิ้นสุดให้หยุด
			break;

		e2 = points->err * 2;
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
				rotate(grid->array[j * grid->col + i], grid, &points.iso_x1, &points.iso_y1);
				rotate(grid->array[j * grid->col + (i + 1)], grid, &points.iso_x2, &points.iso_y2);
				points.index_1 = j * grid->col + i;
				points.index_2 = j * grid->col + i + 1;
				points.z1 = grid->array[j * grid->col + i]->z;
				points.z2 = grid->array[j* grid->col + (i + 1)]->z;
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
	int			i;
	int			j;

	i = 0;
	while (i < grid->col)
	{
		j = 0;
		while (j < grid->row)
		{
			if (j < (grid->row - 1))
			{
				rotate(grid->array[j * grid->col + i], grid, &points.iso_x1, &points.iso_y1);
				rotate(grid->array[(j + 1) * grid->col + i], grid, &points.iso_x2, &points.iso_y2);
				points.index_1 = j * grid->col + i;
				points.index_2 = (j + 1) * grid->col + i;
				points.z1 = grid->array[j * grid->col + i]->z;
				points.z2 = grid->array[(j + 1) * grid->col + i]->z;
				draw_line(&points, vars);
			}
			j++;
		}
		i++;
	}
}
