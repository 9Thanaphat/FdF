/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:11 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/22 07:50:27 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_rad(t_env *env)
{
	env->a_x_rad = env->a_x * (PI / 180);
	env->a_y_rad = env->a_y * (PI / 180);
	env->a_z_rad = env->a_z * (PI / 180);
}

void	rotate(t_list *node, t_env *env, float *sx, float *sy)
{
	float	x;
	float	y;
	float	z;

	x = node->x;
	y = node->y;
	z = node->z * env->z_factor;
	env->temp_y = y * cos(env->a_x_rad) - z * sin(env->a_x_rad);
	env->temp_z = y * sin(env->a_x_rad) + z * cos(env->a_x_rad);
	y = env->temp_y;
	z = env->temp_z;
	env->temp_x = x * cos(env->a_y_rad) + z * sin(env->a_y_rad);
	env->temp_z = -x * sin(env->a_y_rad) + z * cos(env->a_y_rad);
	x = env->temp_x;
	z = env->temp_z;
	env->temp_x = x * cos(env->a_z_rad) - y * sin(env->a_z_rad);
	env->temp_y = x * sin(env->a_z_rad) + y * cos(env->a_z_rad);
	x = env->temp_x;
	y = env->temp_y;
	*sx = round((x * env->cell_size) + env->offset_x);
	*sy = round((y * env->cell_size) + env->offset_y);
}
