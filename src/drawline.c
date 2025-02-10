#include "fdf.h"

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

void	check_color(t_vars *vars, t_points *points, int *color1, int *color2)
{
	*color1 = 0xFFFF00;
	*color2 = 0xFF00FF;
	if (vars->env->array[points->index_1]->color != 0)
		*color1 = vars->env->array[points->index_1]->color;
	if (vars->env->array[points->index_2]->color != 0)
		*color2 = vars->env->array[points->index_2]->color;
}

void	drawline(t_vars *vars, t_points *p)
{
	int		step;
	float	z_curr;
	int		color1;
	int		color2;

	step = 0;
	check_color(vars, p, &color1, &color2);
	while (1)
	{
		z_curr = p->z1 + (p->z2 - p->z1) * ((float)step / p->total_steps);
		my_mlx_pixel_put(vars->img_ptr, p->x1, p->y1, ft_gradient(color1, color2,
			ft_map(z_curr, vars->env->min, vars->env->max)));
		if (p->x1 == p->x2 && p->y1 == p->y2)
			break ;
			p->e2 = 2 * p->err;
		if (p->e2 > -p->dy)
		{
			p->err -= p->dy;
			p->x1 += p->sx;
		}
		if (p->e2 < p->dx)
		{
			p->err += p->dx;
			p->y1 += p->sy;
		}
		step++;
	}
}

void	set_drawline_params(t_vars *vars, t_points *p)
{
	if (p->x1 < p->x2)
	p->sx = 1;
	else
		p->sx = -1;
	if (p->y1 < p->y2)
		p->sy = 1;
	else
		p->sy = -1;
		p->dx = abs(p->x2 - p->x1);
		p->dy = abs(p->y2 - p->y1);
		p->err = p->dx - p->dy;
	if (p->dx > p->dy)
		p->total_steps = p->dx;
	else
		p->total_steps = p->dy;
	drawline(vars, p);
}

void	draw_line_horizontal(t_env *env, t_vars *vars, t_data *img)
{
	t_points	p;
	int			i;
	int			j;

	j = 0;
	while (j < env->row)
	{
		i = 0;
		while (i < env->col)
		{
			if (i < (env->col - 1))
			{
				rotate(env->array[j * env->col + i], env, &p.x1, &p.y1);
				rotate(env->array[j * env->col + (i + 1)], env, &p.x2, &p.y2);
				p.index_1 = j * env->col + i;
				p.index_2 = j * env->col + (i + 1);
				p.z1 = env->array[j * env->col + i]->z;
				p.z2 = env->array[j * env->col + (i + 1)]->z;
				set_drawline_params(vars, &p);
			}
			i++;
		}
		j++;
	}
}

void	draw_line_vertical(t_env *env, t_vars *vars, t_data *img)
{
	t_points	p;
	int			i;
	int			j;

	i = 0;
	while (i < env->col)
	{
		j = 0;
		while (j < env->row)
		{
			if (j < (env->row - 1))
			{
				rotate(env->array[j * env->col + i], env, &p.x1, &p.y1);
				rotate(env->array[(j + 1) * env->col + i], env, &p.x2, &p.y2);
				p.index_1 = j * env->col + i;
				p.index_2 = (j + 1) * env->col + i;
				p.z1 = env->array[j * env->col + i]->z;
				p.z2 = env->array[(j + 1) * env->col + i]->z;
				set_drawline_params(vars, &p);
			}
			j++;
		}
		i++;
	}
}
