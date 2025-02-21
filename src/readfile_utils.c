/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:56 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 14:25:36 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_to_array_extend(int fd, t_env *env, t_list **node)
{
	close(fd);
	to_array(env, *node);
	return (0);
}

void	get_min_max(t_env *env, int val)
{
	if (val < env->min)
		env->min = val;
	if (val > env->max)
		env->max = val;
}

void	set_env(t_env *env)
{
	env->a_x = 45;
	env->a_y = -30;
	env->a_z = 30;
	env->col = 0;
	env->row = 0;
	env->offset_x = 0;
	env->offset_y = 0;
	env->cell_size = 25;
	env->z_factor = 0.25;
	env->z_factor_select = 1;
	env->min = 0;
	env->max = 0;
	env->color1 = 0xe63cc6;
	env->color2 = 0x3ccce6;
	env->array = NULL;
}
