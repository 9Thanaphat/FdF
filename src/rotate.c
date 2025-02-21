/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:11 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 14:40:40 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_list *node, t_env *env, float *sx, float *sy)
{
	float	x;
	float	y;
	float	z;

	x = node->x;
	y = node->y;
	z = node->z * env->z_factor;
	node->temp_y = y * cos(env->a_x * PI / 180) - z * sin(env->a_x * PI / 180);
	node->temp_z = y * sin(env->a_x * PI / 180) + z * cos(env->a_x * PI / 180);
	y = node->temp_y;
	z = node->temp_z;
	node->temp_x = x * cos(env->a_y * PI / 180) + z * sin(env->a_y * PI / 180);
	node->temp_z = -x * sin(env->a_y * PI / 180) + z * cos(env->a_y * PI / 180);
	x = node->temp_x;
	z = node->temp_z;
	node->temp_x = x * cos(env->a_z * PI / 180) - y * sin(env->a_z * PI / 180);
	node->temp_y = x * sin(env->a_z * PI / 180) + y * cos(env->a_z * PI / 180);
	x = node->temp_x;
	y = node->temp_y;
	*sx = round((x * env->cell_size) + env->offset_x);
	*sy = round((y * env->cell_size) + env->offset_y);
}
