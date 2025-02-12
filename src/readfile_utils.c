#include "fdf.h"

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
	env->color1 = 0xFF0000;
	env->color2 = 0x0000FF;
	env->array = NULL;
	env->env_ui = 1;
}
