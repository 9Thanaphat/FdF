/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:40 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 14:32:22 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(t_vars *vars, t_points *p)
{
	if (p->color1 == 0)
		p->color1 = vars->env->color1;
	if (p->color2 == 0)
		p->color2 = vars->env->color2;
}

void	drawline(t_vars *vars, t_points *p)
{
	int		step;
	float	z_curr;

	step = 0;
	check_color(vars, p);
	while (1)
	{
		z_curr = p->z1 + (p->z2 - p->z1) * ((float)step / p->total_steps);
		my_mlx_pixel_put(vars->img_ptr, p->x1, p->y1, ft_gradient(p->color1,
				p->color2, ft_map(z_curr, vars->env->min, vars->env->max)));
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
	p->dx = abs((int)p->x2 - (int)p->x1);
	p->dy = abs((int)p->y2 - (int)p->y1);
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
				p.color1 = env->array[j * env->col + i]->color;
				p.color2 = env->array[j * env->col + (i + 1)]->color;
				rotate(env->array[j * env->col + i], env, &p.x1, &p.y1);
				rotate(env->array[j * env->col + (i + 1)], env, &p.x2, &p.y2);
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
				p.color1 = env->array[j * env->col + i]->color;
				p.color2 = env->array[(j + 1) * env->col + i]->color;
				rotate(env->array[j * env->col + i], env, &p.x1, &p.y1);
				rotate(env->array[(j + 1) * env->col + i], env, &p.x2, &p.y2);
				p.z1 = env->array[j * env->col + i]->z;
				p.z2 = env->array[(j + 1) * env->col + i]->z;
				set_drawline_params(vars, &p);
			}
			j++;
		}
		i++;
	}
}
