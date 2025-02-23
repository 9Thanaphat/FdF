/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:33 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/23 21:10:42 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_offset(int key, t_vars *vars)
{
	if (key == ARROW_UP)
		vars->env->offset_y -= 10;
	else if (key == ARROW_DOWN)
		vars->env->offset_y += 10;
	else if (key == ARROW_LEFT)
		vars->env->offset_x -= 10;
	else if (key == ARROW_RIGHT)
		vars->env->offset_x += 10;
}

void	rotation(int key, t_vars *vars)
{
	if (key == KEY_Q)
		vars->env->a_x += 1;
	if (key == KEY_W)
		vars->env->a_x -= 1;
	if (key == KEY_A)
		vars->env->a_y += 1;
	if (key == KEY_S)
		vars->env->a_y -= 1;
	if (key == KEY_Z)
		vars->env->a_z += 1;
	if (key == KEY_X)
		vars->env->a_z -= 1;
	if (key == KEY_PLUS)
		vars->env->cell_size++;
	if (key == KEY_MINUS && vars->env->cell_size > 1)
		vars->env->cell_size--;
	update_rad(vars->env);
}

void	change_projection(int key, t_vars *vars)
{
	if (key == KEY_R)
	{
		vars->env->a_x = 45;
		vars->env->a_y = -30;
		vars->env->a_z = 30;
	}
	update_rad(vars->env);
}

int	key_press(int key, t_vars *vars)
{
	if (vars->env->move_flag)
	{
		vars->env->move_flag = 0;
		if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
			move_offset(key, vars);
		if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
			|| key == KEY_Z || key == KEY_X || key == KEY_PLUS
			|| key == KEY_MINUS)
			rotation(key, vars);
		if (key == KEY_PAGE_DOWN && vars->env->z_factor_select > 0)
			vars->env->z_factor_select--;
		if (key == KEY_PAGE_UP && vars->env->z_factor_select < 4)
			vars->env->z_factor_select++;
		if (key == KEY_R)
			change_projection(key, vars);
		if (key == ESC)
			close_window(vars);
		redraw(vars);
	}
	vars->env->move_flag = 1;
	return (0);
}
