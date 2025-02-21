/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:46 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 16:57:57 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_read_file(t_env *env, int argc, char **argv)
{
	if (argc == 2)
	{
		if (read_file(argv[1], env) == -1)
		{
			ft_printf("Error opening file!\n");
			exit(0);
			return (-1);
		}
		else
			return (0);
	}
	else
	{
		ft_printf("use ./fdf [file]\n");
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_vars	vars;
	t_data	img;

	if ((check_read_file(&env, argc, argv)) == -1)
		return (0);
	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	vars.env = &env;
	img.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img_ptr = &img;
	my_clear_img(&img);
	draw_line_horizontal(&env, &vars);
	draw_line_vertical(&env, &vars);
	mlx_hook(vars.mlx_window, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	text_display(&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
