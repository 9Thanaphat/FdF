#include "fdf.h"

int	check_read_file(t_env *env, int argc, char **argv)
{
	if (argc == 2)
	{
		if (read_file(argv[1], env) == -1)
		{
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

	if ((check_read_file(&env, argc, argv)) != 0)
		return (0);
	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	vars.env = &env;
	img.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img_ptr = &img;
	draw_line_horizontal(&env, &vars, &img);
	draw_line_vertical(&env, &vars, &img);
	mlx_hook(vars.mlx_window, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	text_display(&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
