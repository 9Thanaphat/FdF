#include "fdf.h"
#include <math.h>

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



int ft_gradient(int start_color, int end_color, int steps, int i)
{
	int r, g, b;

	r = ((start_color >> 16) & 0xFF) + ((((end_color >> 16) & 0xFF) - ((start_color >> 16) & 0xFF)) * (i / (float)(steps - 1)));
	g = ((start_color >> 8) & 0xFF) + ((((end_color >> 8) & 0xFF) - ((start_color >> 8) & 0xFF)) * (i / (float)(steps - 1)));
	b = ((start_color & 0xFF) + (((end_color & 0xFF) - (start_color & 0xFF)) * (i / (float)(steps - 1))));
	return (r << 16 | g << 8 | b);
}

void draw_line(t_points *points, t_vars *vars)
{
    int dx = ft_abs(points->x2 - points->x1);
    int dy = ft_abs(points->y2 - points->y1);
    int dz = ft_abs(points->z2 - points->z1);  // ความแตกต่างของ z
    int sx = (points->x1 < points->x2) ? 1 : -1;
    int sy = (points->y1 < points->y2) ? 1 : -1;
    int err = dx - dy;
    
    int z = points->z1;  // เริ่มต้นที่ z1

    int total_steps = (dx > dy) ? dx : dy;
    int step = 0;

    while (1) {
        // วาดจุดที่ (x1, y1)
        my_mlx_pixel_put(vars->img_ptr, points->x1, points->y1, ft_gradient(0xff00e6, 0x00f7ff, 256, ft_map(z, vars->grid_ptr->min, vars->grid_ptr->max, 0, 255)));

        // หากถึงจุดสิ้นสุดให้หยุด
        if (points->x1 == points->x2 && points->y1 == points->y2)
			break;

        // อัปเดตค่าผิดพลาดและพิกัด
        int e2 = err * 2;
        if (e2 > -dy) { err -= dy; points->x1 += sx; }
        if (e2 < dx) { err += dx; points->y1 += sy; }

        // อัปเดตค่า z ในแต่ละขั้น โดยการไล่จาก z1 ไป z2
		z = points->z1 + ((points->z2 - points->z1) * step) / total_steps;

		step++;
	}
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
				points.x1 = toIso_x(grid, i, j);
				points.y1 = toIso_y(grid, i, j);
				points.x2 = toIso_x(grid, i + 1, j);
				points.y2 = toIso_y(grid, i + 1, j);
				points.z1 = grid->array[j * grid->col + i];
				points.z2 = grid->array[j* grid->col + (i + 1)];
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
				points.x1 = toIso_x(grid, i, j);
				points.y1 = toIso_y(grid, i, j);
				points.x2 = toIso_x(grid, i, j + 1);
				points.y2 = toIso_y(grid, i, j + 1);
				points.z1 = grid->array[j * grid->col + i];
				points.z2 = grid->array[(j + 1)* grid->col + i];
				draw_line(&points, vars);
			}
			j++;
		}
		i++;
	}
}