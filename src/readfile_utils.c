/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:56 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/23 22:25:28 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_to_array_extend(t_env *env, t_list **node)
{
	close(env->fd);
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
	env->offset_x = WIDTH / 2;
	env->offset_y = HEIGHT / 2;
	env->cell_size = 25;
	env->z_factor = 0.25;
	env->z_factor_select = 1;
	env->min = 0;
	env->max = 0;
	env->color1 = 0x2559db;
	env->color2 = 0x4abdff;
	env->array = NULL;
	env->fd = -1;
	env->move_flag = 1;
}

void	adjust_env(t_env *env)
{
	if (env->row >= 100 || env->col >= 100)
		env->cell_size = 10;
	if (env->row >= 150 || env->col >= 150)
		env->cell_size = 6;
	if (env->row >= 250 || env->col >= 250)
		env->cell_size = 5;
	if (env->row >= 500 || env->col >= 500)
		env->cell_size = 2;
}

int	is_fdf(char *file_name)
{
	char	**split;
	int		cmp;

	if (ft_strchr(file_name, '.'))
	{
		split = ft_split(file_name, '.');
		if (split[0] && split[1])
		{
			cmp = ft_strncmp(split[1], "fdf", 3);
			if (cmp != 0)
			{
				free_split(split);
				return (-1);
			}
			else
			{
				free_split(split);
				return (0);
			}
		}
		free_split(split);
	}
	return (-1);
}
