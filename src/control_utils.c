/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:23:02 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/23 20:23:44 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	redraw(t_vars *vars)
{
	set_z_factor(vars);
	my_clear_img(vars->img_ptr);
	draw_line_horizontal(vars->env, vars);
	draw_line_vertical(vars->env, vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window,
		vars->img_ptr->img, 0, 0);
	text_display(vars);
}
